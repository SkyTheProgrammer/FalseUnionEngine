//
// Created by SkyTFB on 10/6/2025.
//
#pragma once

#include <string>
#include <unordered_map>
#include <glm/glm.hpp>

namespace FalseUnion
{
    class Shader {
    public:
        virtual ~Shader() = default;
        
        virtual void Bind() const = 0; // binds a shader 
        virtual void Unbind() const = 0; // unbinds a shader
        virtual const std::string& GetName() const = 0; // gets shader name

        static Ref<Shader> Create(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc);
        static Ref<Shader> Create(const std::string& path);
    protected:
        uint32_t m_RendererID; // renderer's id
        std::string m_Name;
    };

    class ShaderLibrary
    {
    public:
        void Add(const Ref<Shader>& shader);
        void Add(const std::string& name, const Ref<Shader>& shader);
        Ref<Shader> Load(const std::string& path);
        Ref<Shader> Load(const std::string& name, const std::string& path);

        Ref<Shader> Get(const std::string& name);

        bool Exists(const std::string& name) const;
    private:
        std::unordered_map<std::string, Ref<Shader>> m_Shaders;
    };
}
