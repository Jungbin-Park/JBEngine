#include "JBApplication.h"



namespace JB
{
	Application::Application()
		: mHwnd(nullptr), mHdc(nullptr)
	{

	}
	Application::~Application()
	{

	}

	void Application::Initialize(HWND hwnd)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

		mPlayer.SetPosition(0, 0);
		mEllipse.SetPosition(100, 100);
	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update()
	{
		mPlayer.Update();
		mEllipse.Update();
	}

	void Application::LateUpdate()
	{

	}

	void Application::Render()
	{
		mPlayer.Render(mHdc);
		mEllipse.Render(mHdc);
	}
}

