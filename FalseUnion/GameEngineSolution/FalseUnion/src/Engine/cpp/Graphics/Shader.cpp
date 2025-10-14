//
// Created by SkyTFB on 10/7/2025.
//

#include "../../Headers/Graphics/Shader.h"

namespace FalseUnion
{
    /// <summary>
    /// Default shader constructor, assigns its id to be 0
    /// </summary>
    Shader::Shader()
    {
        m_ShaderID = 0;
    }

    /// <summary>
    /// Default deconstructor for use in case of inheritance.
    /// </summary>
    Shader::~Shader() = default;


    /// <summary>
    /// Shader constructor that intakes and sets a shaders id.
    /// </summary>
    /// @param id int, to be set to shaders id
    Shader::Shader(int id)
    {
        m_ShaderID = id;
    }

    /// <summary>
    /// Binds a shader to object.
    /// </summary>
    void Shader::Bind()
    {
    }

    /// <summary>
    /// unbinds a shader from an object.
    /// </summary>
    void Shader::Unbind()
    {
    }

    /// <summary>
    /// Sets a shaders uniform given a name.
    /// </summary>
    void Shader::SetUniform(const std::string* name)
    {
    }

    /// <summary>
    /// Sets a shaders uniform location given a name and id.
    /// </summary>
    /// @param name string, to be set to shaders name in uniform
    /// @param value int, to be set to shaders id in uniform
    void Shader::SetUniform(const std::string* name, int value)
    {
        
    }

    /// <summary>
    /// returns the int value for a shaders location in the uniform list based on its name.
    /// </summary>
    /// @param name string, name to search for in uniform list.
    /// @returns int representing the location of shader in uniform list
    int Shader::GetUniformLocation(const std::string& name)
    {
        return 0;
    }

    /// <summary>
    /// returns the int value for a shaders location in the uniform list based on its id.
    /// </summary>
    /// @param id int, id to search for in the uniform list.
    /// @returns int representing the location of shader in uniform list
    int Shader::GetUniformLocation(const int id)
    {
        return 0;
    }

    /// <summary>
    /// Returns int based on if the shader compiled. takes in type of compile and name of shader.
    /// </summary>
    /// @param type int, representing the type of compile.
    /// @param source string, representing the shaders name.
    /// @returns int representing the status of shader compilation
    int Shader::CompileShader(int type, const std::string* source)
    {
        return 0;
    }

    /// <summary>
    /// Returns int based on if the shader compiled. takes in the type of compile and the id of shader.
    /// </summary>
    /// @param type int, representing the type of compile.
    /// @param id int, representing the shaders name.
    /// @returns int representing the status of shader compilation
    int Shader::CompileShader(int type, const int id)
    {
        return 0;
    }
}
