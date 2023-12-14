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
			Run,
			Sleep,
			GiveWater,
			Attack,
			Axe,
			Pick,
			Sickle,
		};

		enum class eEquipment
		{
			None,
			Sword,
			Axe,
			WateringCan,
			Pick,
			Sickle,
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
		void sickle();
		void run();

	private:
		eState mState;
		class Animator* mAnimator;
		eDirection mDirection;
		eEquipment mEquipment;
		float mSpeed;
	};
}


