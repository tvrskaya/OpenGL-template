#pragma once

#include <glm/glm.hpp>
#include <vector>
#include <memory>

#include "Shader.h"
#include "Camera.h"

class ParticleSystem
{
public:
    ParticleSystem();
    void OnRender(Camera &camera);
    void OnUpdate(float dt);

    struct Particle
    {
        float size;
        glm::vec3 pos;
        glm::vec4 color;
    };
    

private:
    std::vector<Particle> ParticlePool;

    unsigned int VAO = 0;
    Shader m_ParticleShader;
    unsigned int m_ColorLocation, m_ViewLocation, m_ProjectionLocation, m_ModelLocation;
};