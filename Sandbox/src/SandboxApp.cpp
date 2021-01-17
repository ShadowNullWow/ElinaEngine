#include <ElinaEngine.h>

class ExampleLayer : public Elina::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		EL_INFO("ExampleLayer::Update");
	}

	void OnEvent(Elina::Event& event) override
	{
		EL_TRACE("{0}", event);
	}
};

class Sandbox : public Elina::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}
};

Elina::Application* Elina::CreateApplication()
{
	return new Sandbox();
}