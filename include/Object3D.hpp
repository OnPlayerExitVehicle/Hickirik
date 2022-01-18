#pragma once
#include "VertexArray.hpp"
#include "ShaderProgram.hpp"
#include <GLM/mat4x4.hpp>

enum ObjectType3D
{

};

class Object3D
{
private:
    VertexArray* vao;
    Hickirik::Shaders::ShaderProgram* program;
    glm::mat4 transformMatrix;

    static glm::vec3 rightVec;
    static glm::vec3 upVec;
    static glm::vec3 frontVec;

public:
    static void ClearScreen();
    glm::vec3 position;
    glm::vec3 scale;
    glm::vec3 angles;

    Object3D(VertexArray* vao, Hickirik::Shaders::ShaderProgram* program = nullptr);
    void Draw();
};