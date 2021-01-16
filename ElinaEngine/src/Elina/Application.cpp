#include "Application.h"

#include "Elina/Events/ApplicationEvent.h"
#include "Elina/Log.h"

namespace Elina
{
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 920);
		EL_TRACE(e);

		while (true);
	}

}