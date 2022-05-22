#pragma once
#include "ObjectManager2D.hpp"
#include "ObjectManager3D.hpp"

#define WINDOW_WIDTH    1920
#define WINDOW_HEIGHT   1080

#define THREE_DIMENSION

#ifdef THREE_DIMENSION
#define ObjectManager ObjectManager3D
#else
#define ObjectManager ObjectManager2D
#endif