#pragma once

#define WINDOW_WIDTH    800
#define WINDOW_HEIGHT   800

#define THREE_DIMENSION

#ifdef THREE_DIMENSION
#define ObjectManager ObjectManager3D
#else
#define ObjectManager ObjectManager2D
#endif