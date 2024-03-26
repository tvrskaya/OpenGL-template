#version 330 core

in vec3 nearPoint;
in vec3 farPoint;
in mat4 projection;
in mat4 view;

out vec4 color;

vec4 grid(vec3 fragPos3D, float scale)
{
    vec2 coord = fragPos3D.xz * scale;
    vec2 derivative = fwidth(coord);
    vec2 grid = abs(fract(coord - 0.5f) - 0.5f) / derivative;
    float line = min(grid.x, grid.y);
    float minimumz = min(derivative.y, 1);
    float minimumx = min(derivative.x, 1);
    vec4 color = vec4(0.2f, 0.2f, 0.2f, 1.0 - min(line, 1));
    if (fragPos3D.x > -0.1 * minimumx && fragPos3D.x < 0.1 * minimumx)
        color.z = 1.0f;
    if (fragPos3D.z > -0.1 * minimumz && fragPos3D.z < 0.1 * minimumz)
        color.x = 1.0f;
    return color;
}

float computeDepth(vec3 pos)
{
    vec4 clip_space_pos = projection * view * vec4(pos, 1.0f);
    return (clip_space_pos.z/clip_space_pos.w);
}

float computeLinearDepth(vec3 pos)
{
    float far = 100.0f;
    float near = 0.01f;
    vec4 clip_space_pos = projection * view * vec4(pos, 1.0f);
    float clip_space_depth = (clip_space_pos.z / clip_space_pos.w) * 2.0f - 1.0f;
    float linearDepth = (2.0f * near * far) / (far + near - clip_space_depth * (far - near));
    return linearDepth/far;
}

void main()
{
    float t = -nearPoint.y / (farPoint.y - nearPoint.y);
    vec3 fragPos3D = nearPoint + t*(farPoint - nearPoint);

    gl_FragDepth = computeDepth(fragPos3D);

    float linearDepth = computeLinearDepth(fragPos3D);
    float fading = max(0, 0.5f - linearDepth);

    color = (grid(fragPos3D, 10) + grid(fragPos3D, 1) * float(t>0));
    color.a *= fading;
}