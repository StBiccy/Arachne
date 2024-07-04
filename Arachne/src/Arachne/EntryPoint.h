#pragma once

#ifdef ARA_PLATFORM_WINDOWS
extern Arachne::Application* Arachne::CreateAppliaction();

int main(int argc, char** argv)
{
	Arachne::Log::Init();
	ARA_CORE_WARN("INIT LOG");
	int a = 7;
	ARA_INFO("hi var={0}", a);

	auto app = Arachne::CreateAppliaction();
	app->run();
	delete app;
}

#endif // ARA_PLATFROM_WINDOWS

