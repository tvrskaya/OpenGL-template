#pragma once

#include "Camera.h"

#include <GLFW/glfw3.h>

class CameraController
{
public:
    CameraController(float cameraSpeed, float sensetivity, float width, float height);

    void OnUpdate(GLFWwindow *window, float dt);

    Camera& GetCamera() { return m_Camera; }

private:
    Camera m_Camera;

    float Width;
    float Height;

    float CameraSpeed;
    float Sensetivity;

    float lastMouseX;
    float lastMouseY;
    bool firstmouse;
};