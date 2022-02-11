#include "Camera.hpp"
#include <GLM/gtc/matrix_transform.hpp>
#include "DefaultDefinitons.hpp"

const glm::vec3 Camera::rightVec(1.0f, 0.0f, 0.0f);
const glm::vec3 Camera::upVec(0.0f, 1.0f, 0.0f);
const glm::vec3 Camera::frontVec(0.0f, 0.0f, 1.0f);

Camera::Camera(Hickirik::Shaders::ShaderProgram* program)
{
    this->program = program;

    this->position  = glm::vec3(0.0f, 2.0f, 3.0f);
    this->angles    = glm::vec3(-30.0f, 0.0f, 0.0f);
}
void Camera::Draw()
{
    
    angles.x = fmod(angles.x, 360.0f);
    angles.y = fmod(angles.y, 360.0f);
    angles.z = fmod(angles.z, 360.0f);
    

    glm::mat4 translationMatrix = glm::translate(glm::mat4(1), -position);

    glm::mat4 rotationMatrix_X = glm::rotate(glm::mat4(1),glm::radians(angles.x), rightVec);
    glm::mat4 rotationMatrix_Y = glm::rotate(glm::mat4(1),glm::radians(angles.y), upVec);
    glm::mat4 rotationMatrix_Z = glm::rotate(glm::mat4(1),glm::radians(angles.z), frontVec);  

    glm::mat4 rotationMatrix = rotationMatrix_Z * rotationMatrix_Y * rotationMatrix_X;
    
  
    transformMatrix = translationMatrix * rotationMatrix;
    viewMatrix = glm::inverse(rotationMatrix) * translationMatrix;
    projectionMatrix = glm::perspective(glm::radians(90.0f),((float)WINDOW_WIDTH / WINDOW_HEIGHT), 1.0f, 100.0f);


    program->Use();
    program->SendViewMatrix(viewMatrix);
    program->SendProjectionMatrix(projectionMatrix);
}