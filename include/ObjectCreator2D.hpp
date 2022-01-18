#pragma once
#include "VertexArray.hpp"
#include "Object2D.hpp"
#include <map>

class ObjectCreator2D
{
private:
    static VertexArray* createHexagon();
    static VertexArray* createSquare();
    static VertexArray* createTriangle();
    static std::map<ObjectType2D, VertexArray*> vertexMap;

public:
    static VertexArray* CreateObject(ObjectType2D type);
};