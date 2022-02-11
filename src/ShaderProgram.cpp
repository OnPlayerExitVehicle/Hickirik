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

void ShaderProgram::AttachShader(const std::string& address, unsigned int type)
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
    if(!compileStatus)std::cout << address << std::endl;
    //assert(compileStatus);
    glAttachShader(m_id, id);
}

void ShaderProgram::Link()
{
    glLinkProgram(m_id);
    m_transformMatrixId     = glGetUniformLocation(m_id, transformMatrixName.c_str());
    m_viewMatrixId          = glGetUniformLocation(m_id, viewMatrixName.c_str());
    m_projectionMatrixId    = glGetUniformLocation(m_id, projectionMatrixName.c_str());
}

void ShaderProgram::Use()
{
    glUseProgram(m_id);
}

void ShaderProgram::SendTransformMatrix(const glm::mat3& matrix)
{
    glUniformMatrix3fv(m_transformMatrixId, 1, false, &matrix[0][0]);
}

void ShaderProgram::SendTransformMatrix(const glm::mat4& matrix)
{
    glUniformMatrix4fv(m_transformMatrixId, 1, false, &matrix[0][0]);
}

void ShaderProgram::SendViewMatrix(const glm::mat4& matrix)
{
    glUniformMatrix4fv(m_viewMatrixId, 1, false, &matrix[0][0]);
}

void ShaderProgram::SendProjectionMatrix(const glm::mat4& matrix)
{
    glUniformMatrix4fv(m_projectionMatrixId, 1, false, &matrix[0][0]);
}