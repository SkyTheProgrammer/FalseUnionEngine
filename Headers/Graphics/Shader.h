//
// Created by SkyTFB on 10/6/2025.
//

#ifndef FALSEUNION_SHADER_H
#define FALSEUNION_SHADER_H
#include <list>
#include <string>
class Shader {
public:
    Shader(int id);
    void Bind();
    void Unbind();
    void SetUniform(const char *name, int value);
private:
    int m_ShaderID;
    std::list<std::pair<int, std::string>> m_UniformLocationList;
    int CompileShader(int type, const std::string *source);
    int GetUniformLocation(const std::string &name);
};
#endif //FALSEUNION_SHADER_H