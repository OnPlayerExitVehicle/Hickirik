#pragma once
#include <GLM/vec3.hpp>
#include <GLM/vec4.hpp>
#include <GLAD/glad.h>
#include <ShaderProgram.hpp>
#include <GLM/vec2.hpp>
#include <GLM/mat3x3.hpp>
#include <vector>
#include "VertexArray.hpp"

struct ColoredVertex
{
    ColoredVertex(const glm::vec3& pos){
        position = pos;
        color = glm::vec4((rand() % 256) / 256.0f, (rand() % 256) / 256.0f, (rand() % 256) / 256.0f , 1.0f);
    }
    glm::vec3 position;
    glm::vec4 color;
};

typedef std::vector<ColoredVertex> ColoredVertexVector;

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
    /*
    void createHexagon();
    void createSquare();
    void createTriangle();
    */
public:
    static void ClearScreen();
    glm::vec2 position;
    glm::vec2 scale;
    float rotation;
    Object2D(VertexArray* vao, Hickirik::Shaders::ShaderProgram* program = nullptr);
    void Draw();
};