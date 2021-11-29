#include "GUI.hpp"

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

    ImGui::End();
    return isClicked;
}

void GUI::FrameItems(glm::vec2* pos, float* rot, glm::vec2* scale)
{
    ImGui::Begin("Object Controls");
    ImGui::SliderFloat2("Position", (float*)pos, -1.0f, 1.0f, NULL);
    ImGui::SliderFloat("Rotation", rot, 0.0f, 360.0f, NULL);
    ImGui::SliderFloat2("Scale", (float*)scale, 0.0f, 1.0f, NULL);
    ImGui::End();
}

void GUI::Draw()
{
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
