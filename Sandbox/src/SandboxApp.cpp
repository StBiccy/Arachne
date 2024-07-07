#include <Arachne.h>

class Sandbox : public Arachne::Application
{
public:
	Sandbox()
	{

	}
	
	~Sandbox()
	{

	}
};

Arachne::Application* Arachne::CreateAppliaction()
{
	return new Sandbox();
}