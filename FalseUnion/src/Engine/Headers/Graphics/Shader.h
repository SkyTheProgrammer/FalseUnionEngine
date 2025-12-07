//
// Created by SkyTFB on 10/6/2025.
//
#pragma once

#include <string>
#include <glm/glm.hpp>

namespace FalseUnion
{
    class Shader {
    public:
        virtual ~Shader() = default;
        
        virtual void Bind() const = 0; // binds a shader 
        virtual void Unbind() const = 0; // unbinds a shader

        static Shader* Create(const std::string& vertexSrc, const std::string& fragmentSrc);
    protected:
        uint32_t m_RendererID; // renderer's id
    };
}
