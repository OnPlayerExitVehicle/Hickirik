#include "Engine.hpp"

int Engine::frameCounter = 0;
Window Engine::window;

void Engine::Init()
{
	frameCounter = 0;
	
	window.Init(MainLoop);
}

void Engine::Start()
{
	ObjectManager::Start(new Hickirik::Shaders::ShaderProgram(), window.GetWindow());
	window.StartLoop();
}

void Engine::Terminate()
{
	window.Terminate();
}

void Engine::MainLoop()
{
	ObjectManager::Frame();
	std::cout << frameCounter++ << std::endl;
}