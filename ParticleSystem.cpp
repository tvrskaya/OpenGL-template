#include "ParticleSystem.h"
#include "ResourceManager.h"


#include <glad/glad.h>

ParticleSystem::ParticleSystem()
{
    ParticlePool.resize(10);
}

void ParticleSystem::OnRender(Camera &camera)
{
    if (VAO == 0)
    {
        float vertices[] = {
            -0.5f, -0.5f, 0.0f,
             0.5f, -0.5f, 0.0f,
             0.5f,  0.5f, 0.0f,
            -0.5f,  0.5f, 0.0f
        };

        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);

        unsigned int VBO, EBO;
        glGenBuffers(1, &VBO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        unsigned int indices[] = {
            0, 1, 2,
            2, 3, 0
        };

        glGenBuffers(1, &EBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

        m_ParticleShader = ResourceManager::loadShaderFromFile("shaders/particle.vert", "shaders/particle.frag");
    }
}