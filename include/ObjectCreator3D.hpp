#pragma once
#include "VertexArray.hpp"
#include "Object3D.hpp"
#include <map>

class ObjectCreator3D
{
private:
    static VertexArray* createCube();
    static VertexArray* createPyramid();
    static std::map<ObjectType3D, VertexArray*> vertexMap;

public:
    static VertexArray* CreateObject(ObjectType3D type);
};