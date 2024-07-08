#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Arachne {

	class ARACHNE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void run();
	};

	//to be defined in client
	Application* CreateAppliaction();


}

