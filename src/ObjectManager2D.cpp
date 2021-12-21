#include "ObjectManager2D.hpp"

std::vector<Object2D> ObjectManager2D::objectList;
GUI* ObjectManager2D::gui;
Hickirik::Shaders::ShaderProgram* ObjectManager2D::shaderProgram;

void ObjectManager2D::Start(Hickirik::Shaders::ShaderProgram* program, GLFWwindow* window)
{
    gui = new GUI();
    gui->Init(window);
    shaderProgram = program;
    shaderProgram->AttachShader("./shaders/vertex.glsl", GL_VERTEX_SHADER);
    shaderProgram->AttachShader("./shaders/fragment.glsl", GL_FRAGMENT_SHADER);
    shaderProgram->Link();
}

void ObjectManager2D::Frame()
{
    // refactor
    gui->Frame();
    DrawObjects();
    DrawObjectCreator();
    DrawObjectProps();
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
        objectList.push_back(Object2D(type, shaderProgram));
    }
}

void ObjectManager2D::DrawObjectProps()
{
    // refactor
    if(objectList.size() > 0)
    {
        // refactor
        gui->FrameItems(&objectList[0].position, &objectList[0].rotation, &objectList[0].scale);
    }
}