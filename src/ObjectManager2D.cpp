#include "ObjectManager2D.hpp"
#include "ObjectCreator2D.hpp"
#include <iostream>

std::vector<Object2D> ObjectManager2D::objectList;
GUI* ObjectManager2D::gui;
Hickirik::Shaders::ShaderProgram* ObjectManager2D::shaderProgram;
Object2D* ObjectManager2D::activeObject = nullptr;

void ObjectManager2D::Start(Hickirik::Shaders::ShaderProgram* program, GLFWwindow* window)
{
    gui = new GUI();
    gui->Init(window);
    shaderProgram = program;
    shaderProgram->AttachShader("./shaders/2D/vertex.glsl", GL_VERTEX_SHADER);
    shaderProgram->AttachShader("./shaders/2D/fragment.glsl", GL_FRAGMENT_SHADER);
    shaderProgram->Link();
}

void ObjectManager2D::Frame()
{
    // refactor
    gui->Frame();
    DrawObjectCreator();
    DrawObjectProps();
    DrawObjects();
    // refactor
    gui->Draw();
}

void ObjectManager2D::DrawObjects()
{
    Object2D::ClearScreen();
    for(Object2D object: objectList)
    {
        object.Draw();
    }
}

void ObjectManager2D::DrawObjectCreator()
{
    ObjectType2D type;
    if(gui->Creator(type))
    {
        VertexArray* vao = ObjectCreator2D::CreateObject(type);
        objectList.push_back(Object2D(vao, shaderProgram));
        activeObject = &objectList.back();
    }
}

void ObjectManager2D::DrawObjectProps()
{
    // refactor
    if(activeObject)
    {
        // refactor
        gui->FrameItems(&activeObject->position, &activeObject->rotation, &activeObject->scale);
    }
}