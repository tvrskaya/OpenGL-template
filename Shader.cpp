#include "Shader.h"

#include <glad/glad.h>
#include <iostream>
#include <glm/gtc/type_ptr.hpp>

void Shader::UseProgram()
{
    glUseProgram(this->ID);
}

void Shader::CompileShader(const char* vertexCode, const char* fragmentCode, const char* geometryCode)
{
    unsigned int vertexId = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexId, 1, &vertexCode, NULL);
    glCompileShader(vertexId);

    shaderLog(&vertexId, "SHADER", "vertex shader");

    unsigned int fragmentId = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentId, 1, &fragmentCode, NULL);
    glCompileShader(fragmentId);

    shaderLog(&fragmentId, "SHADER", "fragment shader");

    unsigned int geometryId;
    if (geometryCode != nullptr)
    {
        geometryId = glCreateShader(GL_GEOMETRY_SHADER);
        glShaderSource(geometryId, 1, &geometryCode, NULL);
        glCompileShader(geometryId);

        shaderLog(&geometryId, "SHADER", "geometry shader");
    }

    unsigned int program = glCreateProgram();
    glAttachShader(program, vertexId);
    glAttachShader(program, fragmentId);
    if (geometryCode != nullptr)
        glAttachShader(program, geometryId);

    glDeleteShader(vertexId);
    glDeleteShader(fragmentId);
    if (geometryCode != nullptr)
        glDeleteShader(geometryId);

    glLinkProgram(program);
    this->ID = program;
    shaderLog(&program, "PROGRAM", "program");
}

void Shader::SetMatrix4fv(const char* field, glm::mat4 mat)
{
    int matLoc = glGetUniformLocation(this->ID, field);
    glUniformMatrix4fv(matLoc, 1, GL_FALSE, glm::value_ptr(mat));
}

void Shader::SetVector4fv(const char *field, glm::vec4 vec)
{
    int vecLoc = glGetUniformLocation(this->ID, field);
    glUniform4fv(vecLoc, 1, glm::value_ptr(vec));
}

void Shader::SetVector3fv(const char *field, glm::vec3 vec)
{
    int vecLoc = glGetUniformLocation(this->ID, field);
    glUniform3fv(vecLoc, 1, glm::value_ptr(vec));
}

void Shader::shaderLog(unsigned int* obj, const char* target, const char* shaderName)
{
    int success = 0;
    if (target == "SHADER")
    {
        glGetShaderiv(*obj, GL_COMPILE_STATUS, &success);
        if (success == GL_FALSE)
        {
            std::cout << "[LOG] Error: Shader compilation error: " << shaderName << std::endl;
            int logSize = 0;
            glGetShaderiv(*obj, GL_INFO_LOG_LENGTH, &logSize);
            char* infoLog[logSize];
            glGetShaderInfoLog(*obj, logSize, &logSize, infoLog[0]);
            std::cout << "Futher information: " << infoLog << std::endl;
            glDeleteShader(*obj);
            return;
        }
        else
        {
            std::cout << "[LOG] Info: Shader compilation success: " << shaderName << std::endl;
        }
    }
    else if (target == "PROGRAM")
    {
        int isLinked = 0;
        glGetProgramiv(*obj, GL_LINK_STATUS, &isLinked);
        if (isLinked == GL_FALSE)
        {
            std::cout << "[LOG] Error: Program linking error: " << shaderName << std::endl;
            int logSize = 0;
            glGetProgramiv(*obj, GL_INFO_LOG_LENGTH, &logSize);
            char* infoLog[logSize];
            glGetProgramInfoLog(*obj, logSize, &logSize, infoLog[0]);
            std::cout << "Futher information: " << infoLog << std::endl;
            return;
        }
        else 
        {
            std::cout << "[LOG] Info: Program linking success: " << shaderName << std::endl;
        }
    }
}