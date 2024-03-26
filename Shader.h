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
    void SetVector4fv(const char *field, glm::vec4 vec);
    void SetVector3fv(const char *field, glm::vec3 vec);
    void SetVector2fv(const char *field, glm::vec2 vec);
private:
    unsigned int VAO, VBO, EBO;
    void shaderLog(unsigned int* obj, const char* target, const char* shaderName);
};

#endif