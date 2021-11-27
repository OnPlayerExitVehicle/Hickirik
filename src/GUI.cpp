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

void GUI::FrameItems(float* posX, float* posY, float* rot, float* scaleX, float* scaleY)
{
    ImGui::Begin("Object Controls");
    ImGui::SliderFloat("Position X", posX, -1.0f, 1.0f, NULL);
    ImGui::SliderFloat("Position Y", posY, -1.0f, 1.0f, NULL);
    ImGui::SliderFloat("Rotation", rot, 0.0f, 360.0f, NULL);
    ImGui::SliderFloat("Scale X", scaleX, 0.0f, 1.0f, NULL);
    ImGui::SliderFloat("Scale Y", scaleY, 0.0f, 1.0f, NULL);
    ImGui::End();
}

void GUI::Draw()
{
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
