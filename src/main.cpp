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
#include "ObjectManager2D.hpp"
#include "ObjectManager3D.hpp"

int triangleCount;
GLFWwindow* window;
/*
Object2D* object = nullptr;
Object2D* object2 = nullptr;
*/
//std::vector<Object2D*> objects;

//GUI* gui;

void OGL_Start()
{
    srand(time(NULL));
    //gui = new GUI();
    //objects.push_back(new Object2D(ObjectType2D::Triangle));
    ObjectManager::Start(new Hickirik::Shaders::ShaderProgram(), window);
}

void OGL_Frame()
{
    /*
    Object2D::ClearScreen();
    gui->Frame();
    ObjectType2D type;
    if(gui->Creator(type))
    {
        objects.push_back(new Object2D(type));
    }
    for(int i = 0; i < objects.size(); i++)
    {
        objects[i]->Draw();
        gui->FrameItems(&objects[i]->position, &objects[i]->rotation, &objects[i]->scale, i);
    }
    
    /*
    if(object == nullptr)
    {
        ObjectType2D type;
        if(gui->Creator(type)){
            object = new Object2D(type);
        }
    }
    else{
        object->Draw();
        gui->FrameItems(&object->position, &object->rotation, &object->scale);
    }
    
    
    gui->Draw();
    */
   ObjectManager::Frame();
}

void error(int code, const char* error)
{
    std::cout << code << std::endl;
    std::cout << error << std::endl;
}

int main()
{
    glfwInit();
    glfwSetErrorCallback(&error);
    window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Hickirik", NULL, NULL);
    if(window == nullptr)
    {
        std::cout << "err" << std::endl;
    }
    
    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    OGL_Start();

    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        OGL_Frame();
        glfwSwapBuffers(window);
    }

}