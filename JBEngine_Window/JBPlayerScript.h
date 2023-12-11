#pragma once
#include "..\JBEngine_SOURCE\JBScript.h"

namespace JB
{
	class PlayerScript : public Script
	{
	public:
		enum class eState
		{
			Idle,
			Walk,
			Sleep,
			GiveWater,
			Attack,
			Axe,
			Pick,
		};

		enum class eEquipment
		{
			None,
			Sword,
			Axe,
			WateringCan,
			Pick,
		};

		enum class eDirection
		{
			Left,
			Right,
			Down,
			Up,
		};

		PlayerScript();
		~PlayerScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void WaterEvent();

		void OnCollisionEnter(Collider* other) override;
		void OnCollisionStay(Collider* other) override;
		void OnCollisionExit(Collider* other) override;

	private:
		void idle();
		void move();
		void giveWater();
		void axe();
		void attack();
		void pick();

	private:
		eState mState;
		class Animator* mAnimator;
		eDirection mDirection;
		eEquipment mEquipment;
	};
}


