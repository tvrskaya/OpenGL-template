#pragma once

#include <GLFW/glfw3.h>
#include <iostream>

#include "CameraController.h"
#include "LayerStack.h"
#include "Window/Window.h"
#include "Events/Event.h"

class Application
{
public:
    Application(int screenWidth = 800, int screenHeight = 600, const char* title = "OpenGL Sandbox");
    //~Application();

    void Run();
    void End();

    void PushLayer(Layer* layer);
    

private:
    void Update(float dt);
    void Render();
    void OnEvent(Event &e);
    void GuiRender();
private:
    Window* m_Window;
    LayerStack m_LayerStack;
};