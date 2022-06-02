#pragma once

#include "Happy.h"


class HappyAppLayer : public HPY::Layer
{
public:

	HappyAppLayer();
	virtual ~HappyAppLayer();

	void OnAttach() override;
	void OnUpdate(float deltaTime) override;
	void OnDetach() override;
	void OnUIRender() override;
	void OnEvent(HPY::Event& event) override;

private:
	HPY::Ref<HPY::Scene> m_Scene;
};