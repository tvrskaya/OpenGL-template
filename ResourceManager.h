#ifndef RESOURSEMANAGER_H
#define RESOURSEMANAGER_H

#include "Shader.h"

class ResourceManager
{
public:
    static Shader loadShaderFromFile(const char* vertexFile, const char* fragmentFile, const char* geometryFile=nullptr);
private:
    ResourceManager();
    static void logOpenFileError(const char* fileName);
};

#endif