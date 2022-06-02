#pragma once

#include "Happy/Core/KeyCodes.h"
#include "Happy/Core/MouseCodes.h"

#include <glm/glm.hpp>


namespace HPY
{
	class Input
	{
	public:

		static bool IsKeyPressed(KeyCode key);
		static bool IsMouseButtonPressed(MouseCode button);
		
		static glm::vec2 GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};
}