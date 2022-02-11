#pragma once
#include "VertexArray.hpp"
#include "ShaderProgram.hpp"
#include <GLM/mat4x4.hpp>

enum ObjectType3D
{
    Cube, Pyramid
};

class Object3D
{
private:
    VertexArray* vao;
    Hickirik::Shaders::ShaderProgram* program;
    glm::mat4 transformMatrix;

    static const glm::vec3 rightVec;
    static const glm::vec3 upVec;
    static const glm::vec3 frontVec;

    void Update();

public:
    static void ClearScreen();
    glm::vec3 position;
    glm::vec3 scale;
    glm::vec3 angles;

    Object3D(VertexArray* vao, Hickirik::Shaders::ShaderProgram* program = nullptr);
    void Draw();

    bool isUpdated; // refactor
};