cmake_minimum_required(VERSION 3.2)

project(Hickirik)
set(PROJECT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(DEPENDENCIES_DIR ${PROJECT_DIR}/dep)
set(PROJECT_INCLUDE_DIR ${PROJECT_DIR}/include)
set(PROJECT_SOURCE_DIR ${PROJECT_DIR}/src)
set(glfw3_DIR ${DEPENDENCIES_DIR}/GLFW/lib/cmake/glfw3)
find_package(glfw3 3.2 REQUIRED)
set(IMGUI_DIR ${DEPENDENCIES_DIR}/IMGUI)
file(GLOB IMGUI_SOURCEFILES ${IMGUI_DIR}/*.cpp)
add_definitions(-DIMGUI_IMPL_OPENGL_LOADER_GLAD)
set(PROJECT_SOURCES ${PROJECT_SOURCE_DIR}/main.cpp
                    ${DEPENDENCIES_DIR}/GLAD/glad.c
                    ${PROJECT_SOURCE_DIR}/ShaderProgram.cpp
                    ${PROJECT_SOURCE_DIR}/Object2D.cpp
                    ${PROJECT_SOURCE_DIR}/ObjectManager2D.cpp
                    ${PROJECT_SOURCE_DIR}/GUI.cpp
                    ${PROJECT_SOURCE_DIR}/VertexArray.cpp
                    ${PROJECT_SOURCE_DIR}/ObjectCreator2D.cpp
                    ${PROJECT_SOURCE_DIR}/Object3D.cpp
                    ${PROJECT_SOURCE_DIR}/ObjectManager3D.cpp
                    ${PROJECT_SOURCE_DIR}/ObjectCreator3D.cpp
                    ${PROJECT_SOURCE_DIR}/Camera.cpp
                    ${IMGUI_SOURCEFILES}
   )

include_directories(${PROJECT_INCLUDE_DIR} ${DEPENDENCIES_DIR})
add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
target_link_libraries(${PROJECT_NAME} glfw)
