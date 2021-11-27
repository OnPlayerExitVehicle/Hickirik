#pragma once
#include <GLM/vec3.hpp>
#include <GLM/vec4.hpp>
#include <GLAD/glad.h>
#include <ShaderProgram.hpp>
#include <GLM/vec2.hpp>
#include <GLM/mat3x3.hpp>

struct ColoredVertex
{
    ColoredVertex(const glm::vec3& pos){
        position = pos;
        color = glm::vec4((rand() % 256) / 256.0f, (rand() % 256) / 256.0f, (rand() % 256) / 256.0f , 1.0f);
    }
    glm::vec3 position;
    glm::vec4 color;
};

enum ObjectType2D
{
    Triangle, Square, Hexagon
};

class Object2D
{
private:
    unsigned int vao;
    int triangleCount;
    Hickirik::Shaders::ShaderProgram* program;
    glm::mat3 transformMatrix;

    void createHexagon();
    void createSquare();
public:
    static void ClearScreen();
    glm::vec2 position;
    glm::vec2 scale;
    float rotation;
    Object2D(ObjectType2D type, Hickirik::Shaders::ShaderProgram* program = nullptr);
    void Draw();
};