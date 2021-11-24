#include "ShaderProgram.hpp"
#include <GLAD/glad.h>
#include <iostream>
#include <cassert>

using namespace Hickirik::Shaders;

ShaderProgram::ShaderProgram()
{
    m_id = glCreateProgram();
    m_shaderCount = 0;
}

void ShaderProgram::AttachShader(const std::string& address, uint type)
{
    std::string strShader;
    std::fstream file(address);
    char readChar;

        while((readChar = file.get()) != EOF){
            strShader += readChar;
        }
        file.close();

    int id = glCreateShader(type);
    m_shaderIds[m_shaderCount++] = id;

    const char* cstrShader = &strShader[0];
    glShaderSource(id, 1, &cstrShader, 0);
    glCompileShader(id);
    int compileStatus;
    glGetShaderiv(id, GL_COMPILE_STATUS, &compileStatus);
    assert(compileStatus);
    std::cout << compileStatus << std::endl;
    glAttachShader(m_id, id);
}

void ShaderProgram::Link()
{
    glLinkProgram(m_id);
}

void ShaderProgram::Use()
{
    glUseProgram(m_id);
}