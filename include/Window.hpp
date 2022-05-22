#pragma once

#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include <functional>
#include <stdexcept>
#include <Windows.h>
#include "DefaultDefinitons.hpp"

class Window
{
private:
	GLFWwindow* window;
	std::function<void()> loopFunction;
public:
	void Init(std::function<void()> loopFunction);
	void StartLoop();
	void Terminate();

	GLFWwindow* GetWindow() const;
};