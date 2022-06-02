#pragma once

#include "Happy/Renderer/VertexBuffer.h"
#include "Happy/Renderer/IndexBuffer.h"

namespace HPY
{
	class VertexArray
	{
	public:
		VertexArray();
		~VertexArray();

		void Bind() const;
		void Unbind() const;

		void EnableVertexAttributes(const Ref<VertexBuffer>& vertexBuffer);

	private:
		uint32_t m_ID;
	};
}