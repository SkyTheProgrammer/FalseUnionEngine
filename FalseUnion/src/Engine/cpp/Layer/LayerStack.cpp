#include "fupch.h"
#include "../../Headers/Layer/LayerStack.h"

/* design thoughts
 * Layers are supposed to live throughout the entire level of an application
 * Layers shouldn't be destroyed unless the stack is destroyed.
 * Recreating the stack when moving to a new "area" is ideal as it ensures layer destruction.
 */

namespace FalseUnion
{
    /// <summary>
    /// Constructor for lay stack. sets layer insert to Layers begin.
    /// </summary>
    LayerStack::LayerStack()
    {
        m_LayerInsert = m_Layers.begin();
    }

    /// <summary>
    /// Destructor ensures layers are deleted properly.
    /// </summary>
    LayerStack::~LayerStack()
    {
        for (Layer* layer : m_Layers)
            delete layer;
    }

    /// <summary>
    /// pushes a layer and ensures proper placement using the iterator.
    /// </summary>
    /// @param layer Layer*, layer to be inserted into layers.
    void LayerStack::PushLayer(Layer* layer)
    {
        m_LayerInsert = m_Layers.emplace(m_LayerInsert, layer);
    }

    /// <summary>
    /// Pushes layer over every other layer
    /// </summary>
    /// @param overlay Layer*, layer to be pushed as overlay.
    void LayerStack::PushOverlay(Layer* overlay)
    {
        m_Layers.emplace_back(overlay);
    }

    /// <summary>
    /// Pop for layers, finds and pops layer if it exists in layers. DOESN'T DELETE ACTUAL LAYER
    /// </summary>
    /// @param layer Layer*, Layer to be popped.
    void LayerStack::PopLayer(Layer* layer)
    {
        auto deleteLayer = std::find(m_Layers.begin(), m_Layers.end(), layer);
        if (deleteLayer != m_Layers.end())
        {
            m_Layers.erase(deleteLayer);
            m_LayerInsert--;
        }
    }

    /// <summary>
    /// pop for overlay, ensures overlay does what it needs to when detached. uses find for overlay and erases it from layers.
    /// DOESN'T DELETE OVERLAY
    /// </summary>
    /// @param overlay Layer*, overlay layer to be popped from stack.
    void LayerStack::PopOverlay(Layer* overlay)
    {
        auto deleteOverlay = std::find(m_Layers.begin(), m_Layers.end(), overlay);
        if (deleteOverlay != m_Layers.end())
        {
            overlay->OnDetach();
            m_Layers.erase(deleteOverlay);
        }
    }
}
