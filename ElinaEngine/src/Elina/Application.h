#pragma once

#include "elpch.h"
#include "Core.h"
#include "Elina/Events/Event.h"
#include "Elina/Events/ApplicationEvent.h"
#include "Elina/LayerStack.h"

#include "Window.h"

namespace Elina
{
	class ELINA_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
	private:
		bool OnWindowClosed(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	Application* CreateApplication();
}