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

#define WINDOW_WIDTH    800
#define WINDOW_HEIGHT   800

Hickirik::Shaders::ShaderProgram* shaderProgram;

uint vertexArrayObject;

int triangleCount;

struct ColoredVertex
{
    ColoredVertex(const glm::vec3& pos){
        position = pos;
        color = glm::vec4((rand() % 256) / 256.0f, (rand() % 256) / 256.0f, (rand() % 256) / 256.0f , 1.0f);
    }
    glm::vec3 position;
    glm::vec4 color;
};

glm::vec3 triangleVertices[6]{
    glm::vec3(-1.0f,  1.0f, 0.0f), 
    glm::vec3( 0.0f,  1.0f, 0.0f), 
    glm::vec3(-1.0f,  0.0f, 0.0f),
    glm::vec3( 0.0f,  1.0f, 0.0f), 
    glm::vec3( 0.0f,  0.0f, 0.0f), 
    glm::vec3(-1.0f,  0.0f, 0.0f)
};
uint createHexagon()
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

    uint indices[18]{
        0, 2, 3,
        0, 1, 3,
        1, 3, 4,
        2, 3, 5,
        3, 5, 6,
        3, 4, 6
    };

    uint vao, vertexBuffer, indexBuffer;
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
    triangleCount = 6;
    return vao;
}

uint createSquare()
{
    uint vao;
    glm::vec3 vertices[4]{
        glm::vec3(-0.5f,  0.5f, 1.0f),
        glm::vec3( 0.5f,  0.5f, 1.0f),
        glm::vec3(-0.5f, -0.5f, 1.0f),
        glm::vec3( 0.5f, -0.5f, 1.0f)
    };
    uint indexes[6]{
        0, 1, 2, 1, 2, 3
    };
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    uint vertexBuffer, indexBuffer;
    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices[0], GL_STATIC_DRAW);
    glGenBuffers(1, &indexBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indexes), &indexes[0], GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(glm::vec3), NULL);
    glEnableVertexAttribArray(0);
    triangleCount = 2;
    return vao;
}

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
    shaderProgram = new Hickirik::Shaders::ShaderProgram();
    shaderProgram->AttachShader("./shaders/vertex.glsl", GL_VERTEX_SHADER);
    shaderProgram->AttachShader("./shaders/fragment.glsl", GL_FRAGMENT_SHADER);
    shaderProgram->Link();
    glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
    vertexArrayObject = createHexagon();
}

void OGL_Frame()
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    shaderProgram->Use();
    glBindVertexArray(vertexArrayObject);
    glDrawElements(GL_TRIANGLES, triangleCount * 3, GL_UNSIGNED_INT, NULL);
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