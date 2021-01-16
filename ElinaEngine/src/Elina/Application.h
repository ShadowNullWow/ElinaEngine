#pragma once

#include "elpch.h"
#include "Core.h"

namespace Elina
{
	class ELINA_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}