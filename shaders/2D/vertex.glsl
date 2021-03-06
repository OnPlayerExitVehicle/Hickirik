#version 330 core

layout(location = 0) in vec3 inPosition;
layout(location = 1) in vec4 inColor;
out vec4 outColor;
uniform mat3 transformMatrix;

void main()
{
    gl_Position = vec4(transformMatrix * inPosition, 1.0f);
    outColor = inColor;
}