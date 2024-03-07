#include "Camera.h"

#include <glm/gtc/matrix_transform.hpp>

Camera::Camera(float width, float height, glm::vec3 pos, glm::vec3 up, float yaw, float pitch, bool orbital)
                    : Front(glm::vec3(0.0f, 0.0f, -1.0f)), Zoom(45.0f)
{
    this->Width = width;
    this->Height = height;
    this->Position = pos;
    this->WorldUp = up;
    this->Yaw = yaw;
    this->Pitch = pitch;
    this->Orbital = orbital;
    UpdateCameraVectors();
    UpdateMatrices();
}

void Camera::SetPosition(glm::vec3 Position)
{
    this->Position = Position;
}

void Camera::SetAngleOffset(float offsetX, float offsetY)
{
    Yaw += offsetX;
    Pitch += offsetY;


    if (Pitch > 89.0f)
        Pitch = 89.0f;
    if (Pitch < -89.0f)
        Pitch = -89.0f;

    UpdateCameraVectors();
    UpdateMatrices();
}

glm::vec3 Camera::GetPosition()
{
    return Position;
}

glm::mat4 Camera::GetProjectionMatrix()
{
    return m_ProjectionMatrix;
}

glm::mat4 Camera::GetViewMatrix()
{
    return m_ViewMatrix;
}

glm::mat4 Camera::GetProjectionViewMatrix()
{
    return m_ProjectionViewMatrix;
}

void Camera::UpdateCameraVectors()
{
        glm::vec3 front;
        if (Orbital)
        {
            Position.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
            Position.y = sin(glm::sin(glm::radians(Pitch)));
            Position.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
            Position *= Radius;
            front = glm::vec3(0.0f, 0.0f, 0.0f);
            front = front - Position;
        }
        else
        {
            front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
            front.y = sin(glm::radians(Pitch));
            front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
        }
        Front = glm::normalize(front);
        Right = glm::normalize(glm::cross(Front, WorldUp));
        Up =  glm::normalize(glm::cross(Right, Front));
}

void Camera::UpdateMatrices()
{
    m_ViewMatrix = glm::lookAt(Position, Position + Front, Up);
    m_ProjectionMatrix = glm::perspective(glm::radians(Zoom), Width/Height, 0.01f, 100.0f);
    m_ProjectionViewMatrix = m_ProjectionMatrix * m_ViewMatrix;
}