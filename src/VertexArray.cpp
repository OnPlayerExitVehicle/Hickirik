#include "VertexArray.hpp"
#include <GLAD/glad.h>
#include <iostream>

VertexArray::VertexArray(unsigned int id, int indexCount)
{
    this->m_id = id;
    this->m_indexCount = indexCount;
}

void VertexArray::Bind()
{
    glBindVertexArray(m_id);
}

void VertexArray::Unbind()
{
    glBindVertexArray(0);
}

void VertexArray::Draw()
{
    Bind();
    
    glDrawElements(GL_TRIANGLES, m_indexCount, GL_UNSIGNED_INT, 0);
    Unbind();
}