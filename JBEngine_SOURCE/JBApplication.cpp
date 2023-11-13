#include "JBApplication.h"
#include "JBInput.h"
#include "JBTime.h"


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

		Input::Initialize();
		Time::Initialize();

		mPlayer.SetPosition(0, 0);
		//mEllipse.SetPosition(100, 100);
		//mMonster.SetPosition(500, 50);
	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update()
	{
		Input::Update();
		Time::Update();

		mPlayer.Update();
		//mEllipse.Update();
		//mMonster.Update();
	}

	void Application::LateUpdate()
	{

	}

	void Application::Render()
	{
		clearRenderTarget();

		Time::Render(mHdc);
		mPlayer.Render(mHdc);
	}
	void Application::clearRenderTarget()
	{
		// cleear
		Rectangle(mHdc, -1, -1, 1601, 901);
	}
	void Application::copyRenderTarget(HDC source, HDC dest)
	{

	}
}

