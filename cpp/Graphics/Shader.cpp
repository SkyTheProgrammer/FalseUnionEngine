//
// Created by SkyTFB on 10/7/2025.
//

#include "../../Headers/Graphics/Shader.h"

Shader::Shader(int id) {
    m_ShaderID = id;
}

void Shader::Bind() {
}

void Shader::Unbind() {
}

void Shader::SetUniform(const char *name, int value) {
}

int Shader::GetUniformLocation(const std::string &name) {
}

int Shader::CompileShader(int type, const std::string *source) {
}
