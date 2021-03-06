#pragma once

#include "Happy/Core/Layer.h"

namespace HPY
{
	class LayerStack
	{
	public:
		~LayerStack();

		void PushLayer(Layer* layer);
		void PopLayer(Layer* layer);

		void PushOverlay(Layer* overlay);
		void PopOverlay(Layer* overlay);
		
		std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
		std::vector<Layer*>::iterator end() { return m_Layers.end(); }

		std::vector<Layer*>::reverse_iterator rbegin() { return m_Layers.rbegin(); }
		std::vector<Layer*>::reverse_iterator rend() { return m_Layers.rend(); }

	private:
		uint32_t m_LayerInsertIndex = 0;
		std::vector<Layer*> m_Layers;
	};
}