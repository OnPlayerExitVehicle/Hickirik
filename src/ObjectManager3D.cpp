#include "ObjectManager3D.hpp"
#include "ObjectCreator3D.hpp"

std::vector<Object3D> ObjectManager3D::objectList;
GUI* ObjectManager3D::gui;
Hickirik::Shaders::ShaderProgram* ObjectManager3D::shaderProgram;
Object3D* ObjectManager3D::activeObject = nullptr;

void ObjectManager3D::Start(Hickirik::Shaders::ShaderProgram* program, GLFWwindow* window)
{
    gui = new GUI();
    gui->Init(window);
    shaderProgram = program;
    shaderProgram->AttachShader("./shaders/3D/vertex.glsl", GL_VERTEX_SHADER);
    shaderProgram->AttachShader("./shaders/3D/fragment.glsl", GL_FRAGMENT_SHADER);
    shaderProgram->Link();
}

void ObjectManager3D::DrawObjects()
{
    Object3D::ClearScreen();
    for(Object3D object: objectList)
    {
        object.Draw();
    }
}

void ObjectManager3D::DrawObjectCreator()
{
    ObjectType3D type;
    if(gui->Creator(type))
    {
        VertexArray* vao = ObjectCreator3D::CreateObject(type);
        objectList.push_back(Object3D(vao, shaderProgram));
        activeObject = &objectList.back();
    }
}

void ObjectManager3D::DrawObjectProps()
{
    // refactor
    if(activeObject)
    {
        // refactor
        gui->FrameItems(&activeObject->position, &activeObject->angles, &activeObject->scale);
    }
}