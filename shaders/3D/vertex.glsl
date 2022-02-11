#version 330 core

layout(location = 0) in vec3 inPosition;
layout(location = 1) in vec4 inColor;
out vec4 outColor;
uniform mat4 transformMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

void main()
{
    mat4 combinedMatrix = projectionMatrix * viewMatrix * transformMatrix;
    gl_Position = combinedMatrix * vec4(inPosition, 1.0f);
    outColor = inColor;
}