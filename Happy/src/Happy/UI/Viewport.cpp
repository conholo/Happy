#include "hpypch.h"
#include "Happy/UI/Viewport.h"
#include "Happy/Core/Application.h"
#include <imgui.h>

namespace HPY
{
	Ref<Framebuffer> Viewport::s_Framebuffer = nullptr;
	glm::vec2 Viewport::s_ViewportBoundsMax = glm::vec2(0.0f);
	glm::vec2 Viewport::s_ViewportBoundsMin = glm::vec2(0.0f);
	glm::vec2 Viewport::s_ViewportSize = glm::vec2(0.0f);
	bool Viewport::s_ViewportFocused = false;
	bool Viewport::s_ViewportHovered = false;

	void Viewport::Draw()
	{
		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2{ 0, 0 });
		ImGui::Begin("Viewport");
		auto viewportMinRegion = ImGui::GetWindowContentRegionMin();
		auto viewportMaxRegion = ImGui::GetWindowContentRegionMax();
		auto viewportOffset = ImGui::GetWindowPos();
		s_ViewportBoundsMin = { viewportMinRegion.x + viewportOffset.x, viewportMinRegion.y + viewportOffset.y };
		s_ViewportBoundsMax = { viewportMaxRegion.x + viewportOffset.x, viewportMaxRegion.y + viewportOffset.y };

		s_ViewportFocused = ImGui::IsWindowFocused();
		s_ViewportHovered = ImGui::IsWindowHovered();
		Application::GetApplication().GetImGuiLayer().BlockEvents(!s_ViewportFocused && !s_ViewportHovered);

		ImVec2 viewportPanelSize = ImGui::GetContentRegionAvail();
		s_ViewportSize = { viewportPanelSize.x, viewportPanelSize.y };

		uint32_t textureID = s_Framebuffer->GetColorAttachmentID();
		ImGui::Image((void*)textureID, ImVec2{ s_ViewportSize.x, s_ViewportSize.y }, ImVec2{ 0, 1 }, ImVec2{ 1, 0 });
		ImGui::End();
		ImGui::PopStyleVar();
	}
}