#include "HappyAppLayer.h"

#include <imgui/imgui.h>
#include <glm/glm.hpp>

HappyAppLayer::HappyAppLayer()
	:HPY::Layer("Application Layer")
{

}

HappyAppLayer::~HappyAppLayer()
{

}

void HappyAppLayer::OnAttach()
{
	HPY::Application::GetApplication().GetWindow().ToggleIsMaximized();
	m_Scene = HPY::CreateRef<HPY::Scene>("Test Scene");

	HPY::SceneRenderer::LoadScene(m_Scene);
	HPY::SceneRenderer::InitializePipeline();
	HPY::Viewport::SetFramebuffer(HPY::SceneRenderer::GetMainColorBuffer());
	HPY::SceneRenderer::ValidateResize(HPY::Application::GetApplication().GetWindow().GetSize());
}

void HappyAppLayer::OnUpdate(float deltaTime)
{
	HPY::SceneRenderer::ValidateResize(HPY::Viewport::GetViewportSize());
	HPY::SceneRenderer::UpdateEditorCamera(deltaTime);
	HPY::SceneRenderer::SubmitPipeline();
}

void HappyAppLayer::OnDetach()
{
}

void HappyAppLayer::OnUIRender()
{
	HPY::Dockspace::Begin();
	HPY::Dockspace::Draw();
	{
		if (ImGui::BeginMenuBar())
		{
			if (ImGui::BeginMenu("File"))
			{
				ImGui::Separator();
				if (ImGui::MenuItem("Quit"))
					HPY::Application::Close();
				ImGui::Separator();

				ImGui::EndMenu();
			}

			ImGui::EndMenuBar();
		}
	}

	HPY::Viewport::Draw();
	HPY::Dockspace::End();
}

void HappyAppLayer::OnEvent(HPY::Event& event)
{
	HPY::SceneRenderer::OnEvent(event);
}