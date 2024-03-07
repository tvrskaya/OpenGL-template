#ifndef SHADER_H
#define SHADER_H

#include <glm/glm.hpp>

class Shader
{
public:
    unsigned int ID;
    void CompileShader(const char* vertexCode, const char* fragmentCode, const char* geometryCode=nullptr);
    void UseProgram();

    void SetMatrix4fv(const char* field, glm::mat4 mat);
private:
    unsigned int VAO, VBO, EBO;
    void shaderLog(unsigned int* obj, const char* target, const char* shaderName);
};

#endif