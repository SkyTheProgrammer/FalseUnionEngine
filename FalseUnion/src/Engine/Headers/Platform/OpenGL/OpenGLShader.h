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
        OpenGLShader(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc); // Constructor for shader, string shader
        OpenGLShader(const std::string& path); // Constructor for shader, path to shader file
        
        virtual ~OpenGLShader(); 
        void Bind() const override; // binds a shader 
        void Unbind() const override; // unbinds a shader

        void SetMat4(const std::string& name, const glm::mat4& value) override;
        void SetFloat4(const std::string& name, const glm::vec4& value) override;
        void SetFloat3(const std::string& name, const glm::vec3& value) override;
        void SetInt(const std::string& name, int value) override;

        void UploadUniformMat4(const std::string& name, const glm::mat4& matrix);
        void UploadUniformMat3(const std::string& name, const glm::mat3& matrix);
        
        void UploadUniformFloat4(const std::string& name, const glm::vec4 values);
        void UploadUniformFloat3(const std::string& name, glm::vec3 vec);
        void UploadUniformFloat2(const std::string& name, glm::vec2 vec);
        void UploadUniformFloat(const std::string& name, glm::vec1 vec);
        
        void UploadUniformInt(const std::string& name, int value);

        const std::string& GetName() const override
        {
            return m_Name;
        };

    private:
        std::string ReadFile(const std::string& path);
        
        std::unordered_map<GLenum, std::string> PreProcess(const std::string& source);
        void Compile(const std::unordered_map<GLenum, std::string>& shaderSources);
        
    };
}
