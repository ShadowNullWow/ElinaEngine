#pragma once

#ifdef EL_PLATFORM_WINDOWS

extern Elina::Application* Elina::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Elina::CreateApplication();
	app->Run();
	delete app;
}

#endif // EL_PLATFORM_WINDOWS
