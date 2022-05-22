#pragma once

#include "Window.hpp"
#include "DefaultDefinitons.hpp"
#include "ShaderProgram.hpp"
#include <iostream>

class Engine
{
private:
	static Window window;
	static int frameCounter;

	static void MainLoop();
public:
	static void Init();
	static void Start();
	static void Terminate();
};