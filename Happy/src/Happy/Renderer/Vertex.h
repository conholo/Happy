#pragma once

#include <glm/glm.hpp>
#include <vector>

namespace HPY
{
	struct Vertex
	{
		glm::vec3 VertexPosition;
		glm::vec2 TexCoords;
		glm::vec3 Normals;
	};
}