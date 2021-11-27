#include <iostream>
#include <cassert>
#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include <GLM/vec3.hpp>
#include <GLM/vec4.hpp>
#include "ShaderProgram.hpp"
#include "DefaultDefinitons.hpp"
#include <random>
#include <ctime>
#include <vector>
#include "Object2D.hpp"
#include "GUI.hpp"

#define WINDOW_WIDTH    800
#define WINDOW_HEIGHT   800

Hickirik::Shaders::ShaderProgram* shaderProgram;

int triangleCount;

Object2D* object = nullptr;
GUI* gui;

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
    /*
    uint vertexBuffer;
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
    */
    srand(time(NULL));
    
    //object = new Object2D(ObjectType2D::Square);
    gui = new GUI();
}

void OGL_Frame()
{
    gui->Frame();
    
    if(object == nullptr)
    {
        Object2D::ClearScreen();
        ObjectType2D type;
        if(gui->Creator(type))
        {
            std::cout << "asd" << std::endl;
            object = new Object2D(type);
        }
    }
    else{
        object->Draw();
        gui->FrameItems(&object->position.x, &object->position.y, &object->rotation, &object->scale.x, &object->scale.y);
    }
    
    gui->Draw();
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
    gui->Init(window);
    OGL_Start();

    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        OGL_Frame();
        glfwSwapBuffers(window);
    }

}