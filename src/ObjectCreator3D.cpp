#include "ObjectCreator3D.hpp"
#include "VertexUtil.hpp"
#include <GLAD/glad.h>

std::map<ObjectType3D, VertexArray*> ObjectCreator3D::vertexMap;

VertexArray* ObjectCreator3D::createCube()
{
    ColoredVertex vertexList[8]{
        ColoredVertex(glm::vec3(-0.5f,  0.5f, 0.5f)),
        ColoredVertex(glm::vec3( 0.5f,  0.5f, 0.5f)),
        ColoredVertex(glm::vec3(-0.5f, -0.5f, 0.5f)),
        ColoredVertex(glm::vec3( 0.5f, -0.5f, 0.5f)),
        ColoredVertex(glm::vec3(-0.5f,  0.5f, -0.5f)),
        ColoredVertex(glm::vec3( 0.5f,  0.5f, -0.5f)),
        ColoredVertex(glm::vec3(-0.5f, -0.5f, -0.5f)),
        ColoredVertex(glm::vec3( 0.5f,-0.5f, -0.5f))
    };

    std::vector<unsigned int> indiceList{
        0, 1, 2,
        1, 2, 3,
        1, 5, 3,
        5, 3, 7,
        4, 5, 0,
        5, 0, 1,
        5, 4, 7,
        4, 7, 6,
        4, 0, 6,
        0, 6, 2,
        2, 3, 6,
        3, 6, 7
    };
    
    unsigned int vertexArrayId;
    glGenVertexArrays(1, &vertexArrayId);
    glBindVertexArray(vertexArrayId);
    unsigned int vertexBuffer, indexBuffer;
    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexList), &vertexList[0], GL_STATIC_DRAW);
    glGenBuffers(1, &indexBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indiceList.size() * sizeof(unsigned int), &indiceList[0], GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(ColoredVertex), NULL);
    glVertexAttribPointer(1, 4, GL_FLOAT, false, sizeof(ColoredVertex), (const void*)sizeof(glm::vec3));
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glBindVertexArray(0);

    return new VertexArray(vertexArrayId, indiceList.size());
}

VertexArray* ObjectCreator3D::createPyramid()
{
    /*
    ColoredVertexVector vertexList{
        ColoredVertex(glm::vec3(-0.5f,  0.5f, 1.0f)),
        ColoredVertex(glm::vec3( 0.5f,  0.5f, 1.0f)),
        ColoredVertex(glm::vec3(-0.5f, -0.5f, 1.0f)),
        ColoredVertex(glm::vec3( 0.5f, -0.5f, 1.0f))
    };
    std::vector<unsigned int> indiceList{
        0, 1, 2, 1, 2, 3
    };

    unsigned int vertexArrayId;
    glGenVertexArrays(1, &vertexArrayId);
    glBindVertexArray(vertexArrayId);
    unsigned int vertexBuffer, indexBuffer;
    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, vertexList.size() * sizeof(ColoredVertex), &vertexList[0], GL_STATIC_DRAW);
    glGenBuffers(1, &indexBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indiceList.size() * sizeof(unsigned int), &indiceList[0], GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(ColoredVertex), NULL);
    glVertexAttribPointer(1, 4, GL_FLOAT, false, sizeof(ColoredVertex), (const void*)sizeof(glm::vec3));
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    //glBindVertexArray(0);

    return new VertexArray(vertexArrayId, indiceList.size());
    */
   return nullptr;
}

VertexArray* ObjectCreator3D::CreateObject(ObjectType3D type)
{
    if(vertexMap.count(type) > 0)
    {
        return vertexMap[type];
    }
    else
    {
        VertexArray* vertex;
        switch (type)
        {
        case ObjectType3D::Cube:
            vertex = createCube();
            break;
        case ObjectType3D::Pyramid:
            vertex = createPyramid();
            break;
        }
        vertexMap[type] = vertex;
        return vertex;
    }
}