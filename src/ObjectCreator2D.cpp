#include "ObjectCreator2D.hpp"
#include <iostream>

std::map<ObjectType2D, VertexArray*> ObjectCreator2D::vertexMap;

VertexArray* ObjectCreator2D::createHexagon()
{
    ColoredVertex vertexList[7]{
        ColoredVertex(glm::vec3(-0.25f, 0.433f, 1.0f)),
        ColoredVertex(glm::vec3(0.25f, 0.433f, 1.0f)),
        ColoredVertex(glm::vec3(-0.5f, 0.0f, 1.0f)),
        ColoredVertex(glm::vec3(0.0f, 0.0f, 1.0f)),
        ColoredVertex(glm::vec3(0.5f, 0.0f, 1.0f)),
        ColoredVertex(glm::vec3(-0.25f,-0.433f, 1.0f)),
        ColoredVertex(glm::vec3(0.25f,-0.433f, 1.0f))
    };

    std::vector<unsigned int> indiceList{
        0, 2, 3,
        0, 1, 3,
        1, 3, 4,
        2, 3, 5,
        3, 5, 6,
        3, 4, 6
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

VertexArray* ObjectCreator2D::createSquare()
{
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
}

VertexArray* ObjectCreator2D::createTriangle()
{
    ColoredVertex vertexList[3]{
        ColoredVertex(glm::vec3( 0.0f, 0.576f, 1.0f)),
        ColoredVertex(glm::vec3(-0.5f,-0.288f, 1.0f)),
        ColoredVertex(glm::vec3( 0.5f,-0.288f, 1.0f))
    };

    std::vector<unsigned int> indiceList{
        0, 1, 2
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

VertexArray* ObjectCreator2D::CreateObject(ObjectType2D type)
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
        case ObjectType2D::Hexagon:
            vertex = createHexagon();
            break;
        case ObjectType2D::Square:
            vertex = createSquare();
            break;
        case ObjectType2D::Triangle:
            vertex = createTriangle();
            break;
        }
        vertexMap[type] = vertex;
        return vertex;
    }
}