#pragma once

#include <GLFW/glfw3.h>

#include "CameraController.h"

class Application
{
public:
    Application(int screenWidth, int screenHeight, const char* title);
    //~Application();

    void Run();
    void End();

private:
    void Update(float dt);
    //void Render();

private:
    GLFWwindow *window;
    int ScreenWidth;
    int ScreenHeight;

    CameraController m_CameraController;

};