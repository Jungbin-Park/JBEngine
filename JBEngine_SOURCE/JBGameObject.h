#pragma once
#include "CommonInclude.h"
#include "JBComponent.h"

namespace JB
{
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		void Initialize();
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
		std::vector<Component*> mComponents;

	};
}
