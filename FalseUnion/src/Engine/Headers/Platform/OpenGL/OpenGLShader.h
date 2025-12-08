//
// Created by SkyTFB on 10/6/2025.
//
#pragma once

#include "../../Core/Core.h"
#include "../../Graphics/Shader.h"


typedef unsigned int GLenum;

namespace FalseUnion
{
   
    
    class OpenGLShader : public Shader {
    public:
        OpenGLShader(const std::string& vertexSrc, const std::string& fragmentSrc); // Constructor for shader, string shader
        OpenGLShader(const std::string& path); // Constructor for shader, path to shader file
        
        virtual ~OpenGLShader();
        void Bind() const override; // binds a shader 
        void Unbind() const override; // unbinds a shader

        void UploadUniformMat4(const ::std::string& name, const glm::mat4& matrix);
        void UploadUniformMat3(const ::std::string& name, const glm::mat3& matrix);
        
        void UploadUniformFloat4(const ::std::string& name, const glm::vec4 values);
        void UploadUniformFloat3(const char* str, glm::vec3 vec);
        void UploadUniformFloat2(const char* str, glm::vec2 vec);
        void UploadUniformFloat(const char* str, glm::vec1 vec);
        
        void UploadUniformInt(const char* str, int value);

    private:
        std::string ReadFile(const std::string& path);
        
        std::unordered_map<GLenum, std::string> PreProcess(const std::string& source);
        void Compile(const std::unordered_map<GLenum, std::string>& shaderSources);
    };
}
