#include "GUI.hpp"
#include <sstream>

void GUI::Init(GLFWwindow* window)
{
    ImGui::CreateContext();
    ImGui_ImplGlfw_InitForOpenGL(window,true);
    ImGui_ImplOpenGL3_Init("#version 130");
    ImGui::StyleColorsClassic();
}

void GUI::Frame()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

bool GUI::Creator(ObjectType2D& type)
{
    ImGui::Begin("Object Creator");
    bool isClicked = false;
    if(ImGui::Button("Square"))
    {
        type = ObjectType2D::Square;
        isClicked = true;
    } 
    else if(ImGui::Button("Hexagon"))
    {
        type = ObjectType2D::Hexagon;
        isClicked = true;
    }
    else if(ImGui::Button("Triangle"))
    {
        type = ObjectType2D::Triangle;
        isClicked = true;
    }

    ImGui::End();
    return isClicked;
}

bool GUI::Creator(ObjectType3D& type)
{
    ImGui::Begin("Object Creator");
    bool isClicked = false;
    if(ImGui::Button("Cube"))
    {
        type = ObjectType3D::Cube;
        isClicked = true;
    } 
    else if(ImGui::Button("Pyramid"))
    {
        type = ObjectType3D::Pyramid;
        isClicked = true;
    }

    ImGui::End();
    return isClicked;
}

bool GUI::FrameItems(glm::vec2* pos, float* rot, glm::vec2* scale)
{
    ImGui::Begin("Object Controls");
    bool a = ImGui::SliderFloat2("Position", (float*)pos, -1.0f, 1.0f, NULL);
    bool b = ImGui::SliderFloat("Rotation", rot, 0.0f, 360.0f, NULL);
    bool c = ImGui::SliderFloat2("Scale", (float*)scale, 0.0f, 1.0f, NULL);
    ImGui::End();
    return a || b || c;
}

bool GUI::FrameItems(glm::vec3* pos, glm::vec3* rot, glm::vec3* scale)
{
    ImGui::Begin("Object Controls");
    bool a = ImGui::SliderFloat3("Position", (float*)pos, -1.0f, 1.0f, NULL);
    bool b = ImGui::SliderFloat3("Rotation", (float*)rot, 0.0f, 360.0f, NULL);
    bool c = ImGui::SliderFloat3("Scale", (float*)scale, 0.0f, 1.0f, NULL);
    ImGui::End();
    return a || b || c;
}

void GUI::Draw()
{
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
