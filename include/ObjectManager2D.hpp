#pragma once
#include <vector>
#include "Object2D.hpp"
#include "GUI.hpp"
#include "ShaderProgram.hpp"
#include <GLFW/glfw3.h>
#include "ObjectCreator2D.hpp"

class ObjectManager2D
{
    ObjectManager2D() = delete;
    ObjectManager2D(const ObjectManager2D&) = delete;
    ObjectManager2D& operator=(const ObjectManager2D&) = delete;

private:
    static std::vector<Object2D> objectList;
    static Object2D* activeObject;
    static GUI* gui;
    static void DrawObjects();
    static void DrawObjectCreator();
    static void DrawObjectProps();
    static Hickirik::Shaders::ShaderProgram* shaderProgram;
public:
    static void Start(Hickirik::Shaders::ShaderProgram*, GLFWwindow*);
    static void Frame();
};