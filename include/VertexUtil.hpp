#pragma once
#include <GLM/vec3.hpp>
#include <GLM/vec4.hpp>
#include <random>
#include <vector>

struct ColoredVertex
{
    ColoredVertex(const glm::vec3& pos){
        position = pos;
        color = glm::vec4((rand() % 256) / 256.0f, (rand() % 256) / 256.0f, (rand() % 256) / 256.0f , 1.0f);
    }
    glm::vec3 position;
    glm::vec4 color;
};

typedef std::vector<ColoredVertex> ColoredVertexVector;