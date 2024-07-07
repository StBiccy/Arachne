#include "arapch.h"
#include "Application.h"

#include "Events/ApplicationEvents.h"
#include "Arachne/Log.h"

namespace Arachne {
	Arachne::Application::Application()
	{
	}

	Arachne::Application::~Application()
	{
	}

	void Application::run()
	{

		WindowResizeEvent e(100, 200);

		if (e.IsInCategory(EventCategoryApplication))
		{
			ARA_TRACE(e.ToString());
		}

		while (true) 
		{
		}
	}
}
