//
// Created by SkyTFB on 10/7/2025.
//

#include "fupch.h"
#include "../../../Headers/Platform/OpenGL/OpenGLShader.h"

#include <fstream>
#include "glad/glad.h"

#include "../../../Headers/Graphics/Shader.h"
#include "../../../Headers/Core/Core.h"
#include "../../../Headers/Core/Logger.h"

#include <glm/gtc/type_ptr.hpp>

namespace FalseUnion
{
    static GLenum ShaderTypeFromString(const std::string& type)
    {
        if (type == "vertex") return GL_VERTEX_SHADER;
        if (type == "fragment") return GL_FRAGMENT_SHADER;
        if (type == "pixel") return GL_FRAGMENT_SHADER;

        FU_ENGINE_ASSERT(false, "Unknown Shader Type");
        return 0;
    }
    
    OpenGLShader::OpenGLShader(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc)
    {
        m_Name = name;
        std::unordered_map<GLenum, std::string> sources;
        sources[GL_VERTEX_SHADER] = vertexSrc;
        sources[GL_FRAGMENT_SHADER] = fragmentSrc;
        Compile(sources);
    }

    OpenGLShader::OpenGLShader(const std::string& path)
    {
        std::string shaderSource = ReadFile(path);
        auto ShaderSources = PreProcess(shaderSource);
        Compile(ShaderSources);

        // extract name from path
        auto lastSlash = path.find_last_of("/\\");
        lastSlash = lastSlash == std::string::npos ? 0 : lastSlash + 1;
        auto lastDot = path.rfind('.');
        auto count = lastDot == std::string::npos ? path.size() - lastSlash : lastDot - lastSlash;
        m_Name = path.substr(lastSlash, count);
    }

    OpenGLShader::~OpenGLShader()
    {
        glDeleteProgram(m_RendererID);
    }

    void OpenGLShader::Bind() const
    {
        glUseProgram(m_RendererID);
    }

    void OpenGLShader::Unbind() const
    {
        glUseProgram(0);
    }

    void OpenGLShader::UploadUniformMat4(const std::string& name, const glm::mat4& matrix)
    {
        GLint location = glGetUniformLocation(m_RendererID, name.c_str());
        glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
    }

    void OpenGLShader::UploadUniformMat3(const std::string& name, const glm::mat3& matrix)
    {
        GLint location = glGetUniformLocation(m_RendererID, name.c_str());
        glUniformMatrix3fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
    }

    void OpenGLShader::UploadUniformFloat4(const std::string& name, const glm::vec4 values)
    {
        GLint location = glGetUniformLocation(m_RendererID, name.c_str());
        glUniform4f(location, values.x, values.y, values.z, values.w);
    }

    void OpenGLShader::UploadUniformFloat3(const char* str, glm::vec3 vec)
    {
        GLint location = glGetUniformLocation(m_RendererID, str);
        glUniform3f(location, vec.x, vec.y, vec.z);
    }

    void OpenGLShader::UploadUniformFloat2(const char* str, glm::vec2 vec)
    {
        GLint location = glGetUniformLocation(m_RendererID, str);
        glUniform2f(location, vec.x, vec.y);
    }

    void OpenGLShader::UploadUniformFloat(const char* str, glm::vec1 vec)
    {
        GLint location = glGetUniformLocation(m_RendererID, str);
        glUniform1f(location, vec.x);
    }

    void OpenGLShader::UploadUniformInt(const char* str, int value)
    {
        GLint location = glGetUniformLocation(m_RendererID, str);
        glUniform1i(location, value);
    }

    std::string OpenGLShader::ReadFile(const std::string& path)
    {
        std::string result;
        std::ifstream in(path, std::ios::in | std::ios::binary);

        if (in)
        {
            in.seekg(0, std::ios::end);
            result.resize(in.tellg());
            in.seekg(0, std::ios::beg);
            in.read(&result[0], result.size());
            in.close();
        }
        else
        {
            FU_ENGINE_ERROR("Could not open file " + path);
        }
        return result;
    }

    std::unordered_map<GLenum, std::string> OpenGLShader::PreProcess(const std::string& source)
    {
        std::unordered_map<GLenum, std::string> shaderSources;

        const char* typeToken = "#type";
        size_t typeTokenLength = strlen(typeToken);
        size_t pos = source.find(typeToken, 0);
        while (pos != std::string::npos)
        {
            size_t eol = source.find_first_of("\r\n", pos);
            FU_ENGINE_ASSERT(eol != std::string::npos, "Syntax error");
            size_t begin = pos + typeTokenLength + 1;
            std::string type = source.substr(begin, eol - begin);
            FU_ENGINE_ASSERT(type == "vertex" || type == "fragment" || type == "pixel",
                             "Invalid shader type specified.");

            size_t nextLinePos = source.find_first_not_of("\r\n", eol);
            pos = source.find(typeToken, nextLinePos);
            shaderSources[ShaderTypeFromString(type)] = source.substr(nextLinePos,
                                                                      pos - (nextLinePos == std::string::npos
                                                                                 ? source.size() - 1
                                                                                 : nextLinePos));
        }

        return shaderSources;
    }

    void OpenGLShader::Compile(const std::unordered_map<GLenum, std::string>& shaderSources)
    {
        
        GLuint program = glCreateProgram();
        FU_ENGINE_ASSERT(shaderSources.size() <= 2, "Only Support 2 shader right now");
        std::array<GLenum, 2> glShaderIDs;
        int glShaderIDIndex = 0;
        for (auto& keyValue : shaderSources)
        {
            GLenum shaderType = keyValue.first;
            const std::string& source = keyValue.second;

            GLuint shader = glCreateShader(shaderType);

            const GLchar* sourceCString = source.c_str();
            
            glShaderSource(shader, 1, &sourceCString, 0);

            glCompileShader(shader);

            GLint isCompiled = 0;
            glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);
            if (isCompiled == GL_FALSE)
            {
                GLint maxLength = 0;
                glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);

                std::vector<GLchar> infoLog(maxLength);
                glGetShaderInfoLog(shader, maxLength, &maxLength, &infoLog[0]);

                glDeleteShader(shader);

                FU_ENGINE_ERROR("Shader compilation failure!");
                FU_ENGINE_ASSERT(false, "Shader Compilation Error");
                return;
            }
            glAttachShader(program, shader);
            glShaderIDs[glShaderIDIndex++] = shader;
        }

        m_RendererID = program;
        
        /*
        ### v this code is taken directly from the open gl wiki and can be found here https://wikis.khronos.org/opengl/Shader_Compilation#Shader_object_compilation v ###
        */
        
        // Link our program
        glLinkProgram(program);

        // Note the different functions here: glGetProgram* instead of glGetShader*.
        GLint isLinked = 0;
        glGetProgramiv(program, GL_LINK_STATUS, (int*)&isLinked);
        if (isLinked == GL_FALSE)
        {
            GLint maxLength = 0;
            glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);

            // The maxLength includes the NULL character
            std::vector<GLchar> infoLog(maxLength);
            glGetProgramInfoLog(program, maxLength, &maxLength, &infoLog[0]);

            // We don't need the program anymore.
            glDeleteProgram(program);
            // Don't leak shaders either.
            for (auto id : glShaderIDs)
                glDeleteShader(id);


            FU_ENGINE_ERROR("Program Linking Failure!");
            std::string infoLogString(infoLog.begin(), infoLog.end());
            FU_ENGINE_ERROR("Program Linking Log Info: " + infoLogString);
            return;
        }

        // Always detach shaders after a successful link.
        for (auto id : glShaderIDs)
        {
            glDetachShader(program, id);
        }
        /*
        ### ^ this code is taken directly from the open gl wiki and can be found here https://wikis.khronos.org/opengl/Shader_Compilation#Shader_object_compilation ^ ###
        i added a few minor things and changed a few variables names.
         */
    }
}
