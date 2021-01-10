#pragma once

#ifdef EL_PLATFORM_WINDOWS

extern Elina::Application* Elina::CreateApplication();

int main(int argc, char** argv)
{
	Elina::Log::Init();
	EL_CORE_WARN("Initialized Log!");
	int a = 5;
	EL_INFO("Hello! Var={0}", a);

	auto app = Elina::CreateApplication();
	app->Run();
	delete app;
}

#endif // EL_PLATFORM_WINDOWS
