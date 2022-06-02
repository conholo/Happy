#include "Happy.h"
#include "Happy/Core/EntryPoint.h"

#include "HappyAppLayer.h"

class MyApp : public HPY::Application
{
public:
	MyApp()
		:HPY::Application("Happy Application :)")
	{
		PushLayer(new HappyAppLayer());
	}

	~MyApp()
	{

	}
};

HPY::Application* HPY::CreateApplication()
{
	return new MyApp;
}
