#ifndef SANDBOXLAYER_H
#define SANDBOXLAYER_H

#include "Layer.h"
#include "CameraController.h"

class SandboxLayer : public Layer 
{
public:
    SandboxLayer();

    virtual void OnAttach() override;
    virtual void OnDetach() override;
    virtual void OnUpdate(float dt) override;
    virtual void OnEvent(Event* e) override;
    virtual void OnGuiRender() override;
private:
};

#endif