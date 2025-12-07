//
// Created by SkyTFB on 10/6/2025.
//
#pragma once

#include "../../Graphics/Shader.h"

namespace FalseUnion
{
    class OpenGLShader : public Shader {
    public:
        OpenGLShader(const std::string& vertexSrc, const std::string& fragmentSrc); // default constructor for shader
        
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
        
    };
}
