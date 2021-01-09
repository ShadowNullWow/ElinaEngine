#include <ElinaEngine.h>

class Sandbox : public Elina::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Elina::Application* Elina::CreateApplication()
{
	return new Sandbox();
}