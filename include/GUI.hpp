#pragma once
#include <GLAD/glad.h>
#include <GLFW/glfw3.h>

#include<imgui/imgui.h>
#include<imgui/imgui_impl_glfw.h>
#include<imgui/imgui_impl_opengl3.h>

#include "Object2D.hpp"

class GUI
{
public:
    void Init(GLFWwindow* window);
    void Frame();
    bool Creator(ObjectType2D& type);
    void FrameItems(glm::vec2* pos, float* rot, glm::vec2* scale, int number);
    void Draw();
};