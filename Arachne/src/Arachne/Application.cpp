#include "arapch.h"
#include "Application.h"

#include "Events/ApplicationEvents.h"

#include <GLFW/glfw3.h>

namespace Arachne {
	Arachne::Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Arachne::Application::~Application()
	{
	}

	void Application::run()
	{
		while (m_Running) 
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();

		}
	}
}
