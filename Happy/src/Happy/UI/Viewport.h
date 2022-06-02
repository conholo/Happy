#pragma once

#include <glm/glm.hpp>
#include "Happy/Renderer/FrameBuffer.h"
#include "Happy/Core/Memory.h"

namespace HPY
{
	class Viewport
	{
	public:
		static void SetFramebuffer(const Ref<Framebuffer>& framebuffer) { s_Framebuffer = framebuffer; }
		static void Draw();

		static glm::vec2& GetViewportSize() { return s_ViewportSize; }
		static glm::vec2& GetViewportBoundsMin() { return s_ViewportBoundsMin; }
		static glm::vec2& GetViewportBoundsMax() { return s_ViewportBoundsMax; }

	private:
		static Ref<Framebuffer> s_Framebuffer;
		static glm::vec2 s_ViewportSize;
		static glm::vec2 s_ViewportBoundsMin;
		static glm::vec2 s_ViewportBoundsMax;
		static bool s_ViewportFocused;
		static bool s_ViewportHovered;
	};
}

