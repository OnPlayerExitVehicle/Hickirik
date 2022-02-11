#pragma once
#include <GLM/mat4x4.hpp>
#include "ShaderProgram.hpp"

class Camera
{
private:
    glm::mat4 transformMatrix;
    glm::mat4 viewMatrix;
    glm::mat4 projectionMatrix;

    static const glm::vec3 rightVec;
    static const glm::vec3 upVec;
    static const glm::vec3 frontVec;

    Hickirik::Shaders::ShaderProgram* program;

public:
    glm::vec3 position;
    glm::vec3 angles;

    Camera(Hickirik::Shaders::ShaderProgram* program);
    void Draw();
};