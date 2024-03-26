#include "LayerStack.h"

#include <algorithm>
#include <iostream>

void LayerStack::PushLayer(Layer* layer)
{
    
    m_Layers.push_back(layer);
    layer->OnAttach();
}

void LayerStack::PopLayer(Layer *layer)
{
    auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);
    if (it != m_Layers.end())
    {
        layer->OnDetach();
        m_Layers.erase(it);
    }
}

std::vector<Layer*>::iterator LayerStack::begin()
{
    return m_Layers.begin();
}

std::vector<Layer*>::iterator LayerStack::end()
{
    return m_Layers.end();
}