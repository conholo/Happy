#pragma once

#include "Happy/Core/Layer.h"

#include "Happy/Event/WindowEvent.h"
#include "Happy/Event/KeyEvent.h"
#include "Happy/Event/MouseEvent.h"

namespace HPY
{
	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		void OnAttach() override;
		void OnDetach() override;
		void OnEvent(Event& event) override;

		void Begin();
		void End();

		void SetDarkTheme();

		void BlockEvents(bool shouldBlock) { m_BlockEvents = shouldBlock; }
		bool IsBlockingEvents() const { return m_BlockEvents; }

	private:
		bool m_BlockEvents = true;
	};
}