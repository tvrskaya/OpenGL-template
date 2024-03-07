#include <glad/glad.h>
#include "Application.h"

#include <iostream>

Application::Application(int screenWidth, int screenHeight, const char* title)
                            : ScreenWidth(screenWidth), ScreenHeight(screenHeight), m_CameraController(2.5f, 0.1f, ScreenWidth, ScreenHeight)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(ScreenWidth, ScreenHeight, title, NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        End();
    }
    glfwMakeContextCurrent(window);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        End();
    }
    glViewport(0, 0, ScreenWidth, ScreenHeight); 
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
}

void Application::Run()
{
    float deltaTime = 0.0f;
    float lastFrame = 0.0f;

    while(!glfwWindowShouldClose(window))
    {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        Update(deltaTime);
        //Render();

        glfwSwapBuffers(window);
        glfwPollEvents();
        std::cout << "Camera posisitions\n";
        std::cout << "X: " << m_CameraController.GetCamera().GetPosition().x << std::endl; 
        std::cout << "Y: " << m_CameraController.GetCamera().GetPosition().y << std::endl; 
    }
    End();
}

void Application::Update(float dt)
{
    m_CameraController.OnUpdate(window, dt);
}

void Application::End()
{
    glfwTerminate();
    return;
}
