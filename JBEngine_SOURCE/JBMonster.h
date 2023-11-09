#pragma once
#include "CommonInclude.h"

namespace JB
{
	class JBMonster
	{
	public:
		JBMonster();
		~JBMonster();

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

