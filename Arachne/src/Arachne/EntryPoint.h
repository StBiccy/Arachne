#pragma once

#ifdef ARA_PLATFORM_WINDOWS
extern Arachne::Application* Arachne::CreateAppliaction();

int main(int argc, char** argv)
{
	auto app = Arachne::CreateAppliaction();
	app->run();
	delete app;
}

#endif // ARA_PLATFROM_WINDOWS

