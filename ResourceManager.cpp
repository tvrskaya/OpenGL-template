#include "ResourceManager.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

Shader ResourceManager::loadShaderFromFile(const char* vertexFile, const char* fragmentFile, const char* geometryFile)
{
    fstream vertexStream(vertexFile);
    string vertex;
    stringstream vertexString;
    if (vertexStream.is_open())
    {
        vertexString << vertexStream.rdbuf();
        vertex = vertexString.str();
    }
    else
    {
        logOpenFileError(vertexFile);
    }

    fstream fragmentStream(fragmentFile);
    string fragment;
    stringstream fragmentString;
    if (fragmentStream.is_open())
    {
        fragmentString << fragmentStream.rdbuf();
        fragment = fragmentString.str();

    }
    else
    {
        logOpenFileError(fragmentFile);
    }

    fstream geomentryStream(geometryFile);
    string geometry;
    stringstream geometryString;
    if (geometryFile != nullptr)
    {
        if(geomentryStream.is_open())
        {
            geometryString << geomentryStream.rdbuf();
            geometry = geometryString.str();
        }
        else 
        {
            logOpenFileError(geometryFile);
        }
        geomentryStream.close();
    }

    vertexStream.close();
    fragmentStream.close();

    const char* vertexCode = vertex.c_str();
    const char* fragmentCode = fragment.c_str();
    const char* geometryCode = nullptr;
    if (geometryFile != nullptr)
        geometryCode = geometry.c_str(); 

    Shader shader;
    shader.CompileShader(vertexCode, fragmentCode, geometryCode);
    return shader;
}

void ResourceManager::logOpenFileError(const char* filename)
{
        cout << "[LOG] Error: can't open file: " << filename << endl;
}