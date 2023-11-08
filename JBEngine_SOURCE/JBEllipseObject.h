#pragma once
#include "CommonInclude.h"


namespace JB
{
	class EllipseObject
	{
	public:
		EllipseObject();
		~EllipseObject();

		void Update();
		void LateUpdate();
		void Render(HDC hdc);

		void SetPosition(float x, float y)
		{
			mX = x;
			mY = y;
		}

		float GetPositionX() { return mX; }
		float GetPositionY() { return mY; }


	private:
		//float mSpeed;
		float mX;
		float mY;
	};
}
