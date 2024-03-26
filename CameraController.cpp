#include "CameraController.h"

CameraController::CameraController(float cameraSpeed, float sensetivity, float width, float height)
                                    : CameraSpeed(cameraSpeed), Sensetivity(sensetivity), Width(width), Height(height), m_Camera(Height, Width), firstmouse(true)
{
}

void CameraController::OnUpdate(GLFWwindow *window, float dt)
{
    if(glfwGetKey(window, GLFW_KEY_A))
    {
        glm::vec3 pos = m_Camera.GetPosition();
        pos.x -= CameraSpeed * dt;
        m_Camera.SetPosition(pos);
    }
    if(glfwGetKey(window, GLFW_KEY_D))
    {
        glm::vec3 pos = m_Camera.GetPosition();
        pos.x += CameraSpeed * dt;
        m_Camera.SetPosition(pos);
    }
    if(glfwGetKey(window, GLFW_KEY_W))
    {
        glm::vec3 pos = m_Camera.GetPosition();
        pos.z -= CameraSpeed * dt;
        m_Camera.SetPosition(pos);
    }
    if(glfwGetKey(window, GLFW_KEY_S))
    {
        glm::vec3 pos = m_Camera.GetPosition();
        pos.z += CameraSpeed * dt;
        m_Camera.SetPosition(pos);
    }

    double xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);
    float fXpos = static_cast<float>(xpos);
    float fYpos = static_cast<float>(ypos);
    if (firstmouse)
    {
        lastMouseX = fXpos;
        lastMouseY = fYpos;
        firstmouse = false;
    }

    float offsetX = (lastMouseX - fXpos) * Sensetivity;
    float offsetY = (lastMouseY - fYpos) * Sensetivity;
    lastMouseX = fXpos;
    lastMouseY = fYpos;

    m_Camera.SetAngleOffset(offsetX, offsetY);
}