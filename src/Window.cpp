#include "Window.hpp"

void Window::Init(std::function<void()> loopFunction)
{
	glfwInit();
	window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_WIDTH, "Hickirik", NULL, NULL);
	glfwMakeContextCurrent(window);
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	this->loopFunction = loopFunction;
}

void Window::StartLoop()
{
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		loopFunction();
		glfwSwapBuffers(window);
	}
}

void Window::Terminate()
{
	glfwDestroyWindow(window);
	glfwTerminate();
}

GLFWwindow* Window::GetWindow() const
{
	return window;
}