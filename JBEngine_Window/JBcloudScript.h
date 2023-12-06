#pragma once
#include "..\JBEngine_SOURCE\JBScript.h"
#include "..\JBEngine_SOURCE\JBTransform.h"

namespace JB
{
	class cloudScript : public Script
	{
	public:
		cloudScript();
		~cloudScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	private:
		void move();
		
		void translate(Transform* tr);

	private:
		class Animator* mAnimator;
	};
}


