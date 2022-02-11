#pragma once
#include <GLM/vec3.hpp>
#include <GLM/vec4.hpp>
#include <GLAD/glad.h>
#include <ShaderProgram.hpp>
#include <GLM/vec2.hpp>
#include <GLM/mat3x3.hpp>
#include <vector>
#include "VertexArray.hpp"
#include "VertexUtil.hpp"

enum ObjectType2D
{
    Triangle, Square, Hexagon
};

class Object2D
{
private:
    VertexArray* vao;
    Hickirik::Shaders::ShaderProgram* program;
    glm::mat3 transformMatrix;
    
    void Update();
public:
    static void ClearScreen();
    glm::vec2 position;
    glm::vec2 scale;
    float rotation;
    Object2D(VertexArray* vao, Hickirik::Shaders::ShaderProgram* program = nullptr);
    void Draw();

    bool isUpdated; // refactor
};