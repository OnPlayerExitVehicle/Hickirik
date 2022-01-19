#pragma once
#include <GLAD/glad.h>
#include <GLFW/glfw3.h>

#include<imgui/imgui.h>
#include<imgui/imgui_impl_glfw.h>
#include<imgui/imgui_impl_opengl3.h>

#include "Object2D.hpp"
#include "Object3D.hpp"

class GUI
{
public:
    void Init(GLFWwindow* window);
    void Frame();
    bool Creator(ObjectType2D& type);
    bool Creator(ObjectType3D& type);
    void FrameItems(glm::vec2* pos, float* rot, glm::vec2* scale);
    void FrameItems(glm::vec3* pos, glm::vec3* rot, glm::vec3* scale);
    void Draw();
};