#include <iostream>
#include <cassert>
#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include <GLM/vec3.hpp>
#include "ShaderProgram.hpp"
#include "DefaultDefinitons.hpp"

#define WINDOW_WIDTH    800
#define WINDOW_HEIGHT   800

Hickirik::Shaders::ShaderProgram* shaderProgram;

uint vertexArrayObject;
uint vertexBuffer;

glm::vec3 triangleVertices[6]{
    glm::vec3(-1.0f,  1.0f, 0.0f), 
    glm::vec3( 0.0f,  1.0f, 0.0f), 
    glm::vec3(-1.0f,  0.0f, 0.0f),
    glm::vec3( 0.0f,  1.0f, 0.0f), 
    glm::vec3( 0.0f,  0.0f, 0.0f), 
    glm::vec3(-1.0f,  0.0f, 0.0f)
};

void OGL_Start()
{
    glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
    shaderProgram = new Hickirik::Shaders::ShaderProgram();
    shaderProgram->AttachShader("./shaders/vertex.glsl", GL_VERTEX_SHADER);
    shaderProgram->AttachShader("./shaders/fragment.glsl", GL_FRAGMENT_SHADER);
    shaderProgram->Link();
    glGenVertexArrays(1, &vertexArrayObject);
    glBindVertexArray(vertexArrayObject);
    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(triangleVertices), triangleVertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, NULL);
    glEnableVertexAttribArray(0);
}

void OGL_Frame()
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    shaderProgram->Use();
    glBindVertexArray(vertexArrayObject);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glDrawArrays(GL_TRIANGLES, 3, 6);
}

void error(int code, const char* error)
{
    std::cout << code << std::endl;
    std::cout << error << std::endl;
}

int main()
{
    //assert(glfwInit());
    glfwInit();
    glfwSetErrorCallback(&error);
    GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "asd", NULL, NULL);
    if(window == nullptr)
    {
        std::cout << "err" << std::endl;
    }
    
    //assert(window);
    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    //assert();

    OGL_Start();

    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        OGL_Frame();
        glfwSwapBuffers(window);
    }

}