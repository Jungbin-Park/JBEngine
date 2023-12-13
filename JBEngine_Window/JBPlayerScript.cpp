#include "JBPlayerScript.h"
#include "JBInput.h"
#include "JBTransform.h"
#include "JBTime.h"
#include "JBGameObject.h"
#include "JBAnimator.h"

namespace JB
{
	PlayerScript::PlayerScript()
		: mState(PlayerScript::eState::Idle)
		, mAnimator(nullptr)
		, mDirection(eDirection::Down)
		, mEquipment(eEquipment::None)
	{
	}
	PlayerScript::~PlayerScript()
	{
	}
	void PlayerScript::Initialize()
	{
	}
	void PlayerScript::Update()
	{
		if (mAnimator == nullptr)
		{
			mAnimator = GetOwner()->GetComponent<Animator>();
		}

		switch (mState)
		{
		case JB::PlayerScript::eState::Idle:
			idle();
			break;
		case JB::PlayerScript::eState::Walk:
			move();
			break;
		case JB::PlayerScript::eState::Sleep:
			break;
		case JB::PlayerScript::eState::GiveWater:
			giveWater();
			break;
		case JB::PlayerScript::eState::Attack:
			attack();
			break;
		case JB::PlayerScript::eState::Axe:
			axe();
			break;
		case JB::PlayerScript::eState::Pick:
			pick();
			break;
		case JB::PlayerScript::eState::Sickle:
			sickle();
			break;
		default:
			break;
		}
	}
	void PlayerScript::LateUpdate()
	{
	}
	void PlayerScript::Render(HDC hdc)
	{
	}
	void PlayerScript::WaterEvent()
	{
		int a = 0;
	}
	void PlayerScript::OnCollisionEnter(Collider* other)
	{
		other->GetOwner()->GetComponent<Transform>()->SetPosition(Vector2(400.0f, 500.0f));
	}
	void PlayerScript::OnCollisionStay(Collider* other)
	{
	}
	void PlayerScript::OnCollisionExit(Collider* other)
	{
	}
	void PlayerScript::idle()
	{
		switch (mDirection)
		{
		case JB::PlayerScript::eDirection::Left:
			mAnimator->PlayAnimation(L"LeftIdle");
			break;
		case JB::PlayerScript::eDirection::Right:
			mAnimator->PlayAnimation(L"RightIdle");
			break;
		case JB::PlayerScript::eDirection::Down:
			mAnimator->PlayAnimation(L"DownIdle");
			break;
		case JB::PlayerScript::eDirection::Up:
			mAnimator->PlayAnimation(L"UpIdle");
			break;
		default:
			break;
		}

		if (Input::GetKey(eKeyCode::D))
		{
			mState = PlayerScript::eState::Walk;
			mAnimator->PlayAnimation(L"RightWalk");
		}
		if (Input::GetKey(eKeyCode::A))
		{
			mState = PlayerScript::eState::Walk;
			mAnimator->PlayAnimation(L"LeftWalk");
		}
		if (Input::GetKey(eKeyCode::W))
		{
			mState = PlayerScript::eState::Walk;
			mAnimator->PlayAnimation(L"UpWalk");
		}
		if (Input::GetKey(eKeyCode::S))
		{
			mState = PlayerScript::eState::Walk;
			mAnimator->PlayAnimation(L"DownWalk");
		}
		if (Input::GetKey(eKeyCode::Num1))
		{
			mEquipment = PlayerScript::eEquipment::Sword;
		}
		if (Input::GetKey(eKeyCode::Num2))
		{
			mEquipment = PlayerScript::eEquipment::Axe;
		}
		if (Input::GetKey(eKeyCode::Num3))
		{
			mEquipment = PlayerScript::eEquipment::WateringCan;
		}
		if (Input::GetKey(eKeyCode::Num4))
		{
			mEquipment = PlayerScript::eEquipment::Pick;
		}
		if (Input::GetKey(eKeyCode::Num5))
		{
			mEquipment = PlayerScript::eEquipment::Sickle;
		}
		if (Input::GetKey(eKeyCode::LButton))
		{
			switch (mEquipment)
			{
			case JB::PlayerScript::eEquipment::None:
				break;
			case JB::PlayerScript::eEquipment::Sword:
			{
				mState = PlayerScript::eState::Attack;
				switch (mDirection)
				{
				case JB::PlayerScript::eDirection::Left:
					mAnimator->PlayAnimation(L"LeftAttack", false);
					break;
				case JB::PlayerScript::eDirection::Right:
					mAnimator->PlayAnimation(L"RightAttack", false);
					break;
				case JB::PlayerScript::eDirection::Down:
					mAnimator->PlayAnimation(L"DownAttack", false);
					break;
				case JB::PlayerScript::eDirection::Up:
					mAnimator->PlayAnimation(L"UpAttack", false);
					break;
				default:
					break;
				}
				break;
			}
			case JB::PlayerScript::eEquipment::Axe:
			{
				mState = PlayerScript::eState::Axe;
				switch (mDirection)
				{
				case JB::PlayerScript::eDirection::Left:
					mAnimator->PlayAnimation(L"LeftAxe", false);
					break;
				case JB::PlayerScript::eDirection::Right:
					mAnimator->PlayAnimation(L"RightAxe", false);
					break;
				case JB::PlayerScript::eDirection::Down:
					mAnimator->PlayAnimation(L"DownAxe", false);
					break;
				case JB::PlayerScript::eDirection::Up:
					mAnimator->PlayAnimation(L"UpAxe", false);
					break;
				default:
					break;
				}
				break;
			}
			case JB::PlayerScript::eEquipment::WateringCan:
			{
				mState = PlayerScript::eState::GiveWater;
				switch (mDirection)
				{
				case JB::PlayerScript::eDirection::Left:
					mAnimator->PlayAnimation(L"LeftGiveWater", false);
					break;
				case JB::PlayerScript::eDirection::Right:
					mAnimator->PlayAnimation(L"RightGiveWater", false);
					break;
				case JB::PlayerScript::eDirection::Down:
					mAnimator->PlayAnimation(L"DownGiveWater", false);
					break;
				case JB::PlayerScript::eDirection::Up:
					mAnimator->PlayAnimation(L"UpGiveWater", false);
					break;
				default:
					break;
				}
				break;
			}
			case JB::PlayerScript::eEquipment::Pick:
			{
				mState = PlayerScript::eState::Pick;
				switch (mDirection)
				{
				case JB::PlayerScript::eDirection::Left:
					mAnimator->PlayAnimation(L"LeftPick", false);
					break;
				case JB::PlayerScript::eDirection::Right:
					mAnimator->PlayAnimation(L"RightPick", false);
					break;
				case JB::PlayerScript::eDirection::Down:
					mAnimator->PlayAnimation(L"DownPick", false);
					break;
				case JB::PlayerScript::eDirection::Up:
					mAnimator->PlayAnimation(L"UpPick", false);
					break;
				default:
					break;
				}
				break;
			}
			case JB::PlayerScript::eEquipment::Sickle:
			{
				mState = PlayerScript::eState::Sickle;
				switch (mDirection)
				{
				case JB::PlayerScript::eDirection::Left:
					mAnimator->PlayAnimation(L"LeftSickle", false);
					break;
				case JB::PlayerScript::eDirection::Right:
					mAnimator->PlayAnimation(L"RightSickle", false);
					break;
				case JB::PlayerScript::eDirection::Down:
					mAnimator->PlayAnimation(L"DownSickle", false);
					break;
				case JB::PlayerScript::eDirection::Up:
					mAnimator->PlayAnimation(L"UpSickle", false);
					break;
				default:
					break;
				}
				break;
			}
			default:
				break;
			}
			
			//Vector2 mousePos = Input::GetMousePosition();
		}
	}
	void PlayerScript::move()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (Input::GetKey(eKeyCode::D))
		{
			pos.x += 100.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::A))
		{
			pos.x -= 100.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::W))
		{
			pos.y -= 100.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::S))
		{
			pos.y += 100.0f * Time::DeltaTime();
		}

		tr->SetPosition(pos);

		if (Input::GetKeyUp(eKeyCode::D))
		{
			mDirection = eDirection::Right;
			mState = PlayerScript::eState::Idle;
			mAnimator->PlayAnimation(L"Idle", false);
		}
		else if (Input::GetKeyUp(eKeyCode::A))
		{
			mDirection = eDirection::Left;
			mState = PlayerScript::eState::Idle;
			mAnimator->PlayAnimation(L"Idle", false);
		}
		else if (Input::GetKeyUp(eKeyCode::W))
		{
			mDirection = eDirection::Up;
			mState = PlayerScript::eState::Idle;
			mAnimator->PlayAnimation(L"Idle", false);
		}
		else if (Input::GetKeyUp(eKeyCode::S))
		{
			mDirection = eDirection::Down;
			mState = PlayerScript::eState::Idle;
			mAnimator->PlayAnimation(L"Idle", false);
		}
	}

	void PlayerScript::giveWater()
	{
		if (mAnimator->IsComplete())
		{
			mState = eState::Idle;
			//mAnimator->PlayAnimation(L"DownIdle", false);
		}
	}

	void PlayerScript::axe()
	{
		if (mAnimator->IsComplete())
		{
			mState = eState::Idle;
		}
	}

	void PlayerScript::attack()
	{
		if (mAnimator->IsComplete())
		{
			mState = eState::Idle;
		}
	}

	void PlayerScript::pick()
	{
		if (mAnimator->IsComplete())
		{
			mState = eState::Idle;
		}
	}

	void PlayerScript::sickle()
	{
		if (mAnimator->IsComplete())
		{
			mState = eState::Idle;
		}
	}
}