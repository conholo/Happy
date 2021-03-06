#pragma once

#include "Happy/Renderer/Shader.h"
#include "Happy/Renderer/Material.h"
#include "Happy/Renderer/Framebuffer.h"
#include <glm/glm.hpp>

namespace HPY
{
	struct RenderPassSpecification
	{
		Ref<Framebuffer> TargetFramebuffer;
		Ref<Shader> Shader;
		Ref<Material> Material;
		uint32_t Flags;

		bool DepthWrite = true;
		bool DepthRead = true;
		bool ColorWrite = true;
		glm::vec4 ClearColor{ 0.0f };
	};

	class RenderPass
	{
	public:
		RenderPass(const RenderPassSpecification& specification);

		RenderPassSpecification& GetRenderPassSpecification() { return m_Specification; }
		const RenderPassSpecification& GetRenderPassSpecification() const { return m_Specification; }

	private:
		RenderPassSpecification m_Specification;
	};
}