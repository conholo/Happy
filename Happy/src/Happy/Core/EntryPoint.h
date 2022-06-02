#pragma once

extern HPY::Application* HPY::CreateApplication();

int main()
{
	HPY::Log::Init();
	auto* app = HPY::CreateApplication();
	app->Run();
	delete app;
}