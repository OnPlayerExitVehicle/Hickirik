#include "Object3D.hpp"
#include <GLAD/glad.h>
#include <GLM/gtc/matrix_transform.hpp>


const glm::vec3 Object3D::rightVec(1.0f, 0.0f, 0.0f);
const glm::vec3 Object3D::upVec(0.0f, 1.0f, 0.0f);
const glm::vec3 Object3D::frontVec(0.0f, 0.0f, 1.0f);


Object3D::Object3D(VertexArray* vao, Hickirik::Shaders::ShaderProgram* program)
{
    this->isUpdated = true;

    position        = glm::vec3(0.0f, 0.0f, 0.0f);
    scale           = glm::vec3(1.0f, 1.0f, 1.0f);
    angles          = glm::vec3(0.0f, 0.0f, 0.0f);
    Update();

    this->vao = vao;

    
    glEnable(GL_DEPTH_TEST);
    if(!program)
    {
        this->program = new Hickirik::Shaders::ShaderProgram();
        this->program->AttachShader("./shaders/3D/vertex.glsl", GL_VERTEX_SHADER);
        this->program->AttachShader("./shaders/3D/fragment.glsl", GL_FRAGMENT_SHADER);
        this->program->Link();
    }
    else this->program = program;
}

void Object3D::Update()
{
    angles.x = fmod(angles.x, 360.0f);
    angles.y = fmod(angles.y, 360.0f);
    angles.z = fmod(angles.z, 360.0f);

    glm::mat4 translationMatrix = glm::translate(glm::mat4(1), position);
    glm::mat4 scalingMatrix     = glm::scale(glm::mat4(1), scale);
    
    glm::mat4 rotationMatrix_X = glm::rotate(glm::mat4(1), glm::radians(angles.x), rightVec);
    glm::mat4 rotationMatrix_Y = glm::rotate(glm::mat4(1), glm::radians(angles.y), upVec);
    glm::mat4 rotationMatrix_Z = glm::rotate(glm::mat4(1), glm::radians(angles.z), frontVec);

    glm::mat4 rotationMatrix = rotationMatrix_X * rotationMatrix_Y * rotationMatrix_Z;

    transformMatrix = translationMatrix * rotationMatrix * scalingMatrix;
    isUpdated = false;
}

void Object3D::Draw()
{
    if(true || isUpdated)
    {
        Update();
    }

    program->Use();
    program->SendTransformMatrix(transformMatrix); //?

    vao->Draw();
}

void Object3D::ClearScreen() // refactor
{
    glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}