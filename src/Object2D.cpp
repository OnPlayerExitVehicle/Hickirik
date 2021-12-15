#include "Object2D.hpp"
#include <GLM/gtx/matrix_transform_2d.hpp>
#include <iostream>

Object2D::Object2D(ObjectType2D type, Hickirik::Shaders::ShaderProgram* program)
{
    position        = glm::vec2(0.0f, 0.0f);
    scale           = glm::vec2(1.0f, 1.0f);
    rotation        = 0.0f;
    transformMatrix = glm::mat3(1);

    glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
    if(!program)
    {
        this->program = new Hickirik::Shaders::ShaderProgram();
        this->program->AttachShader("./shaders/vertex.glsl", GL_VERTEX_SHADER);
        this->program->AttachShader("./shaders/fragment.glsl", GL_FRAGMENT_SHADER);
        this->program->Link();
    }
    else this->program = program;
    
    switch (type)
    {
    case ObjectType2D::Hexagon:
            createHexagon();
        break;
    
    case ObjectType2D::Square:
            createSquare();
        break;
    
    case ObjectType2D::Triangle:
            createTriangle();
        break;
    }
}

void Object2D::Draw()
{
    rotation = fmod(rotation, 360.0f);
    glm::mat3 rotationMatrix = glm::rotate(glm::mat3(1), glm::radians(rotation));
    glm::mat3 translationMatrix = glm::translate(glm::mat3(1), position);
    glm::mat3 scalingMatrix = glm::scale(glm::mat3(1), scale);
    transformMatrix = translationMatrix * rotationMatrix * scalingMatrix;

    glClear(GL_COLOR_BUFFER_BIT);
    program->Use();
    glBindVertexArray(vao);

    program->SendTransformMatrix(transformMatrix);

    glDrawElements(GL_TRIANGLES, triangleCount * 3, GL_UNSIGNED_INT, NULL);
    glBindVertexArray(0);
}

void Object2D::createHexagon()
{
    ColoredVertex vertexList[7]{
        ColoredVertex(glm::vec3(-0.25f, 0.433f, 1.0f)),
        ColoredVertex(glm::vec3(0.25f, 0.433f, 1.0f)),
        ColoredVertex(glm::vec3(-0.5f, 0.0f, 1.0f)),
        ColoredVertex(glm::vec3(0.0f, 0.0f, 1.0f)),
        ColoredVertex(glm::vec3(0.5f, 0.0f, 1.0f)),
        ColoredVertex(glm::vec3(-0.25f,-0.433f, 1.0f)),
        ColoredVertex(glm::vec3(0.25f,-0.433f, 1.0f))
    };

    unsigned int indices[18]{
        0, 2, 3,
        0, 1, 3,
        1, 3, 4,
        2, 3, 5,
        3, 5, 6,
        3, 4, 6
    };
    
    unsigned int vertexBuffer, indexBuffer;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexList), &vertexList[0], GL_STATIC_DRAW);
    glGenBuffers(1, &indexBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), &indices[0], GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(ColoredVertex), NULL);
    glVertexAttribPointer(1, 4, GL_FLOAT, false, sizeof(ColoredVertex), (const void*)sizeof(glm::vec3));
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glBindVertexArray(0);
    triangleCount = 6;
}

void Object2D::createSquare()
{
    ColoredVertex vertexList[4]{
        ColoredVertex(glm::vec3(-0.5f,  0.5f, 1.0f)),
        ColoredVertex(glm::vec3( 0.5f,  0.5f, 1.0f)),
        ColoredVertex(glm::vec3(-0.5f, -0.5f, 1.0f)),
        ColoredVertex(glm::vec3( 0.5f, -0.5f, 1.0f))
    };
    unsigned int indices[6]{
        0, 1, 2, 1, 2, 3
    };
    
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    unsigned int vertexBuffer, indexBuffer;
    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexList), &vertexList[0], GL_STATIC_DRAW);
    glGenBuffers(1, &indexBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), &indices[0], GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(ColoredVertex), NULL);
    glVertexAttribPointer(1, 4, GL_FLOAT, false, sizeof(ColoredVertex), (const void*)sizeof(glm::vec3));
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glBindVertexArray(0);
    triangleCount = 2;
}

void Object2D::createTriangle()
{
    ColoredVertex vertexList[3]{
        ColoredVertex(glm::vec3( 0.0f, 0.576f, 1.0f)),
        ColoredVertex(glm::vec3(-0.5f,-0.288f, 1.0f)),
        ColoredVertex(glm::vec3( 0.5f,-0.288f, 1.0f))
    };

    unsigned int indices[3]{
        0, 1, 2
    };
    
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    unsigned int vertexBuffer, indexBuffer;
    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexList), &vertexList[0], GL_STATIC_DRAW);
    glGenBuffers(1, &indexBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), &indices[0], GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(ColoredVertex), NULL);
    glVertexAttribPointer(1, 4, GL_FLOAT, false, sizeof(ColoredVertex), (const void*)sizeof(glm::vec3));
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glBindVertexArray(0);
    triangleCount = 1;
}
void Object2D::ClearScreen()
{
    glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}