#pragma once

class VertexArray
{
private:
    unsigned int m_id;
    int m_indexCount;
    void Bind();
    void Unbind();
public:
    VertexArray(unsigned int id, int indexCount);
    
    void Draw();
};