#pragma once
#include <vector>
#include "Object2D.hpp"

class ObjectManager2D
{
private:
    std::vector<Object2D> objectList;
public:
    ObjectManager2D();
};