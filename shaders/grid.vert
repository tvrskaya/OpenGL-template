#version 330 core

layout(location=0) in vec3 position;

out vec3 nearPoint;
out vec3 farPoint;
out mat4 projection;
out mat4 view;

uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;

vec3 UnprojectPoint(float x, float y, float z, mat4 view, mat4 projection)
{
    mat4 viewInv = inverse(view);
    mat4 projectionInt = inverse(projection);
    vec4 unprojectedPoint = viewInv * projectionInt * vec4(x, y, z, 1.0f);
    return unprojectedPoint.xyz/unprojectedPoint.w;
}

void main()
{
    vec3 p = position;
    nearPoint = UnprojectPoint(p.x, p.y, 0.0f, viewMatrix, projectionMatrix);
    farPoint = UnprojectPoint(p.x, p.y, 1.0f, viewMatrix, projectionMatrix);
    projection = projectionMatrix;
    view = viewMatrix;
    gl_Position = vec4(p, 1.0f);
}