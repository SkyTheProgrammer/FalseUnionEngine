//
// Created by SkyTFB on 10/6/2025.
//
#pragma once
#include <list>
#include <string>

namespace FalseUnion
{
    class Shader {
    public:
        Shader(); // default constructor for shader
        virtual ~Shader(); // default virtual destructor in case of inheratence
        Shader(int id); // shader constructor with id
        void Bind(); // binds a shader 
        void Unbind(); // unbinds a shader
        void SetUniform(const std::string *name); //sets a shaders uniform given a name
        void SetUniform(const std::string *name, int value); // sets a shaders uniform with a reference name and id
        int GetUniformLocation(const std::string &name); // gets a shaders uniform location given its name.
        int GetUniformLocation(const int id); // gets a shaders uniform location given its id.
    private:
        int m_ShaderID; // shaders id
        static std::list<std::pair<int, std::string>> m_UniformLocationList; // Shaders uniform location list
        int CompileShader(int type, const std::string *source); // compiles a shader based on name
        int CompileShader(int type, const int id); // compiles a shader based on id
    };
}
