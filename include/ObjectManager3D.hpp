#pragma once
#include "Object3D.hpp"
#include <vector>
#include "GUI.hpp"
#include <GLFW/glfw3.h>

class ObjectManager3D
{
    ObjectManager3D() = delete;
    ObjectManager3D(const ObjectManager3D&) = delete;
    ObjectManager3D& operator=(const ObjectManager3D&) = delete;

private:
    static std::vector<Object3D> objectList;
    static Object3D* activeObject;
    static GUI* gui;
    static void DrawObjects();
    static void DrawObjectCreator();
    static void DrawObjectProps();
    static Hickirik::Shaders::ShaderProgram* shaderProgram;

public:
    static void Start(Hickirik::Shaders::ShaderProgram*, GLFWwindow* window);
    static void Frame();
};