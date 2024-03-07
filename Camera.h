#pragma once

#include <glm/glm.hpp>

class Camera
{
public:
    Camera(float width, float height, glm::vec3 pos = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), float yaw = -90.0f, float pitch = 0.0f, bool orbital = false);

    void SetPosition(glm::vec3 Position);

    void SetAngleOffset(float offsetX, float offsetY);

    glm::vec3 GetPosition();

    glm::mat4 GetProjectionMatrix();
    glm::mat4 GetViewMatrix();
    glm::mat4 GetProjectionViewMatrix();

private:
    void UpdateCameraVectors();
    void UpdateMatrices();
private:
    float Width;
    float Height;

    glm::mat4 m_ProjectionMatrix;
    glm::mat4 m_ViewMatrix;
    glm::mat4 m_ProjectionViewMatrix;

    glm::vec3 Position;
    glm::vec3 Front;
    glm::vec3 Up;
    glm::vec3 Right;
    glm::vec3 WorldUp;

    float Yaw;
    float Pitch;

    float Zoom;

    bool Orbital;
    float Radius;
};