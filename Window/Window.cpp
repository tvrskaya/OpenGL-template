
#include <glad/glad.h>
#include <iostream>
#include "Window.h"
#include "../Events/MouseEvents.h"
#include "../Events/KeyEvents.h"

Window::Window(int width, int height, const char* title)
            : width(width), height(height), title(title)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_Window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (m_Window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
    }
    glfwMakeContextCurrent(m_Window);
    glfwSetInputMode(m_Window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    glfwSetInputMode(m_Window, GLFW_STICKY_MOUSE_BUTTONS, GLFW_TRUE);
    glfwSetInputMode(m_Window, GLFW_STICKY_KEYS, GLFW_TRUE);
    glfwSetWindowUserPointer(m_Window, (void*)&EventCallbackFn);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
    }
    glViewport(0, 0, width, height); 
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);


    glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xpos, double ypos){
        float xPosf = static_cast<float>(xpos);
        float yPosf = static_cast<float>(ypos);

        MousePosEvent mousePosEvent(xPosf, yPosf);


        std::function<void(Event&)> EventCallback = *(std::function<void(Event&)>*)glfwGetWindowUserPointer(window);


        EventCallback((Event&)mousePosEvent);
    });

    glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods) {
        MouseButtonEvent mouseButtonEvent(button, action);

        std::function<void(Event&)> EventCallback = *(std::function<void(Event&)>*)glfwGetWindowUserPointer(window);
        
        EventCallback((Event&)mouseButtonEvent);
    });

    glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xoffset, double yoffset){
        float offsetX = static_cast<float>(xoffset);
        float offsetY = static_cast<float>(yoffset);

        MouseScrollEvent mouseScrollEvet(offsetX, offsetY);

        std::function<void(Event&)> EventCallback = *(std::function<void(Event&)>*)glfwGetWindowUserPointer(window);

        EventCallback((Event&)mouseScrollEvet);
    });

    glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods){
        KeyEvent keyEvent(key, action);

        std::function<void(Event&)> EventCallback = *(std::function<void(Event&)>*)glfwGetWindowUserPointer(window);

        EventCallback((Event&)keyEvent);
    });
}

void Window::OnUpdate()
{
    glfwSwapBuffers(m_Window);
    glfwPollEvents();
}

GLFWwindow* Window::GetWindow()
{
    return m_Window;
}

void Window::SetEventCallbackFn(const std::function<void(Event&)>& callback)
{
    EventCallbackFn = callback;
}