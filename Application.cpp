#include <glad/glad.h>
#include "Application.h"

#include <iostream>

Application::Application(int screenWidth, int screenHeight, const char* title)
{
    m_Window = new Window(screenWidth, screenHeight, title);
    m_Window->SetEventCallbackFn(std::bind(&Application::OnEvent, this, std::placeholders::_1));
}

void Application::PushLayer(Layer* layer)
{
    m_LayerStack.PushLayer(layer);
}

void Application::Run()
{
    float deltaTime = 0.0f;
    float lastFrame = 0.0f;

    while(!glfwWindowShouldClose(m_Window->GetWindow()))
    {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        Update(deltaTime);
        GuiRender();

        m_Window->OnUpdate();
    }
    End();
}

void Application::Update(float dt)
{
    for (auto layer = m_LayerStack.begin(); layer != m_LayerStack.end(); layer++)
    {

        (*layer)->OnUpdate(dt);
    }
}

void Application::GuiRender()
{
    for (auto layer = m_LayerStack.begin(); layer != m_LayerStack.end(); layer++)
    {
        (*layer)->OnGuiRender();
    }
}

void Application::OnEvent(Event &e)
{
    for (auto layer = m_LayerStack.end() - 1; layer != m_LayerStack.begin() - 1; layer--)
    {
        if (!e.IsHandled())
        {
            (*layer)->OnEvent(&e);
        }
        else 
        {
            break;
        }
    }
}

void Application::End()
{
    glfwTerminate();
    return;
}
