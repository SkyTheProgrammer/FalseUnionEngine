#pragma once

#include "Layer.h"

#include <vector>

namespace FalseUnion
{
    class FALSEUNION_API LayerStack // stack data structure for layers as the most recent is the most important
    {
    public:
        LayerStack();
        ~LayerStack(); // used to ensure vector is empty and deleted properly.

        void PushLayer(Layer* layer); // pushes a layer to the correct position on stack
        void PushOverlay(Layer* overlay); // forces layer to top position
        void PopLayer(Layer* layer); // pop for normal layer
        void PopOverlay(Layer* overlay); // pop for overlay layer.

        std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
        std::vector<Layer*>::iterator end() { return m_Layers.end(); }

    private:
        std::vector<Layer*> m_Layers; // vector storing new layers
        std::vector<Layer*>::iterator m_LayerInsert; // manager for vectors ensuring proper placement.
        // ^ this is such a cool data structure
    };
}
