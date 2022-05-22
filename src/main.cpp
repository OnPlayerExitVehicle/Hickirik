#include <iostream>
#include <cassert>
#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include <GLM/vec3.hpp>
#include <GLM/vec4.hpp>
#include "ShaderProgram.hpp"
#include "DefaultDefinitons.hpp"
#include <random>
#include <ctime>
#include <vector>
#include "Object2D.hpp"
#include "GUI.hpp"
#include "ObjectManager2D.hpp"
#include "ObjectManager3D.hpp"
#include "Engine.hpp"

int main()
{
    Engine engine;
    engine.Init();
    engine.Start();
    engine.Terminate();
}