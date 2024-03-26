#include "Application.h"
#include "SandboxLayer.h"

#include <iostream>

class SandboxApplication : public Application
{
public:
    SandboxApplication()
    {
        PushLayer(new SandboxLayer());
    }
};

int main(void)
{
    SandboxApplication app;
    

    app.Run();
    return 0;
}