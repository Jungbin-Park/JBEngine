#pragma once
#include "..\\JBEngine_SOURCE\\JBGameObject.h"

namespace JB
{
	class Cat : public GameObject
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:

	};
}


