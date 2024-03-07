#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 color;

out vec4 aColor;

uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

void main()
{
    gl_Position = projectionMatrix*viewMatrix*modelMatrix*vec4(position, 1);
    aColor = vec4(color, 1.0f);
}