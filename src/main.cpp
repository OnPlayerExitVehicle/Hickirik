#include <iostream>
#include <cassert>
#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include "ShaderProgram.hpp"


#define WINDOW_WIDTH    800
#define WINDOW_HEIGHT   600

void OGL_Start()
{
    glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
    Hickirik::Shaders::ShaderProgram sp;
    sp.AttachShader("./shaders/vertex.glsl", GL_VERTEX_SHADER);
}

void OGL_Frame()
{
    glClear(GL_COLOR_BUFFER_BIT);
}

int main()
{
    assert(glfwInit());

    GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Hickirik", NULL, NULL);
    assert(window);
    glfwMakeContextCurrent(window);
    assert(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress));

    OGL_Start();

    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        OGL_Frame();
        glfwSwapBuffers(window);
    }

}