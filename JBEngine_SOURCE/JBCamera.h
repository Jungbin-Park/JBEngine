#pragma once
#include "JBComponent.h"

namespace JB
{
	using namespace JB::math;
	class Camera : public Component
	{
	public:
		// operator ¿¬»êÀÚ·Î µ¡¼À »¬¼À ±¸Çö(JBmath.h)
		Vector2 CalculatePosition(Vector2 pos) { return pos - mDistance; }
		Vector2 CalculateTilePosition(Vector2 pos) { return pos + mDistance; }

		Camera();
		~Camera();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetTarget(GameObject* target) { mTarget = target; }

	private:
		class GameObject* mTarget;
		Vector2 mDistance;
		Vector2 mResolution;
		Vector2 mLookPosition;
	};
}


