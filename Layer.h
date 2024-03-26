#ifndef LAYER_H
#define LAYER_H

#include <string>
#include "Events/Event.h"

class Layer
{
public:
    Layer(const std::string &name = "Layer");

    virtual void OnAttach() {}
    virtual void OnDetach() {}
    virtual void OnUpdate(float dt) {}
    virtual void OnEvent(Event* e) {}
    virtual void OnGuiRender() {}
protected:
    std::string m_Name;
};

#endif