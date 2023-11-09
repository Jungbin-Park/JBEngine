#pragma once
#include "JBGameObject.h"
#include "JBEllipseObject.h"
#include "JBMonster.h"

namespace JB
{
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND hwnd);
		void Run();
		void Update();
		void LateUpdate();
		void Render();

	private:
		HWND mHwnd;
		HDC mHdc;

		GameObject mPlayer;
		EllipseObject mEllipse;
		JBMonster mMonster;
	};
}

