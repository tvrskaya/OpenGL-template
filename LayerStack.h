#ifndef LAYERSTACK_H
#define LAYERSTACK_H

#include <vector>

#include "Layer.h"

class LayerStack
{
public:
    LayerStack() {};
    void PopLayer(Layer *layer);
    void PushLayer(Layer* layer);

    std::vector<Layer*>::iterator begin();
    std::vector<Layer*>::iterator end();

private:
    std::vector<Layer*> m_Layers;
};

#endif