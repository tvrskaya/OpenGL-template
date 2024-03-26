#ifndef WINDOW_H
#define WINDOW_H

#include <GLFW/glfw3.h>
#include <functional>

#include "../Events/Event.h"

class Window
{
public:
    Window(int width, int height, const char* title);
    void OnUpdate();
    GLFWwindow* GetWindow();
    void SetEventCallbackFn(const std::function<void(Event&)>& callback);
private:
    GLFWwindow* m_Window;
    int width;
    int height;
    const char* title;

    std::function<void(Event&)> EventCallbackFn;

};

#endif