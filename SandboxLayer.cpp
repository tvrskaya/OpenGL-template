#include <iostream>

#include "SandboxLayer.h"
#include "Events/MouseEvents.h"
#include "Events/KeyEvents.h"

#define LOG(x) std::cout << x << std::endl;

SandboxLayer::SandboxLayer()
{
}

void SandboxLayer::OnAttach()
{
    std::cout << "Attached" << std::endl;
}

void SandboxLayer::OnDetach()
{
    std::cout << "Detached" << std::endl;
}

void SandboxLayer::OnUpdate(float dt)
{
    //std::cout << "OnUpdate" << std::endl;
}

void SandboxLayer::OnEvent(Event* e)
{
    e->Handle();
    switch (e->GetEventType())
    {
    case mousePosEvent:
    {
        MousePosEvent mousePos = (MousePosEvent&)*e;
        LOG("Mouse Position: ");
        LOG(mousePos.GetX());
        LOG(mousePos.GetY());
        LOG("END");
        break;
    }
    case mouseButtonClickEvent:
    {
        MouseButtonEvent mouseButton = (MouseButtonEvent&)*e;
        LOG("Mouse button: ");
        LOG(mouseButton.GetButton());
        const char* state_name;
        if (mouseButton.GetState() == GLFW_PRESS)
            state_name = "PRESS";
        else if (mouseButton.GetState() == GLFW_RELEASE)
            state_name = "RELEASE";
        LOG(state_name);
        LOG("END");
        break;
    }
    case mouseScrollEvent:
    {
        MouseScrollEvent mouseScroll = (MouseScrollEvent&)*e;
        LOG("Mouse scroll event");
        LOG(mouseScroll.GetOffsetX());
        LOG(mouseScroll.GetOffsetY());
        break;
    }
    case keyEvent:
    {
        KeyEvent keyPressedEvent = (KeyEvent&)*e;
        LOG("Key event: ");
        const char* key_name = glfwGetKeyName(keyPressedEvent.GetKey(), 0);
        LOG(key_name);
        const char* state_name;
        if (keyPressedEvent.GetState() == GLFW_PRESS)
            state_name = "PRESS";
        else if (keyPressedEvent.GetState() == GLFW_RELEASE)
            state_name = "RELEASE";
        else if (keyPressedEvent.GetState() == GLFW_REPEAT)
            state_name = "REPEAT";
        LOG(state_name);
        LOG("END");
        break;
    }
    }
}

void SandboxLayer::OnGuiRender()
{

}