//
// Created by SkyTFB on 10/6/2025.
//
#pragma once

#include <string>

namespace FalseUnion
{
    class Shader {
    public:
        Shader(const std::string& vertexSrc, const std::string& fragmentSrc); // default constructor for shader
        
        virtual ~Shader();
        void Bind() const; // binds a shader 
        void Unbind() const; // unbinds a shader
        
    private:
        uint32_t m_RendererID; // renderer's id
    };
}
