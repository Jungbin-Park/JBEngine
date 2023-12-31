#include "JBCatScript.h"
#include "JBInput.h"
#include "JBTransform.h"
#include "JBTime.h"
#include "JBGameObject.h"
#include "JBAnimator.h"
#include "JBObject.h"

namespace JB
{
	CatScript::CatScript()
		: mState(CatScript::eState::SitDown)
		, mAnimator(nullptr)
		, mTime(0.0f)
		, mDeathTime(0.0f)
		, mDirection(eDirection::Down)
	{
	}
	CatScript::~CatScript()
	{
	}
	void CatScript::Initialize()
	{
	}
	void CatScript::Update()
	{
		/*mDeathTime += Time::DeltaTime();
		if (mDeathTime > 6.0f)
		{
			object::Destroy(GetOwner());
		}*/

		if (mAnimator == nullptr)
		{
			mAnimator = GetOwner()->GetComponent<Animator>();
		}

		switch (mState)
		{
		case JB::CatScript::eState::SitDown:
			sitDown();
			break;
		case JB::CatScript::eState::Walk:
			move();
			break;
		case JB::CatScript::eState::Sleep:
			break;
		case JB::CatScript::eState::Attack:
			break;
		default:
			break;
		}
	}
	void CatScript::LateUpdate()
	{
	}
	void CatScript::Render(HDC hdc)
	{
	}
	void CatScript::sitDown()
	{
		mTime += Time::DeltaTime();
		if (mTime > 3.0f)
		{
			mState = CatScript::eState::Walk;
			int direction = (rand() % 4);
			mDirection = (eDirection)direction;
			PlayWalkAnimationByDirection(mDirection);
			mTime = 0.0f;
		}
	}
	void CatScript::move()
	{
		mTime += Time::DeltaTime();
		if (mTime > 2.0f)
		{
			int isLayDown = rand() % 2;
			if (isLayDown)
			{
				mState = eState::LayDown;
				mAnimator->PlayAnimation(L"LayDown", false);
			}
			else
			{
				mState = eState::SitDown;
				mAnimator->PlayAnimation(L"SitDown", false);
			}
		}

		Transform* tr = GetOwner()->GetComponent<Transform>();
		translate(tr);
	}
	void CatScript::layDown()
	{
		mTime += Time::DeltaTime();
		if (mTime > 3.0f)
		{
			mState = CatScript::eState::Walk;
			int direction = (rand() % 4);
			mDirection = (eDirection)direction;
			PlayWalkAnimationByDirection(mDirection);
			mTime = 0.0f;
		}
	}
	void CatScript::PlayWalkAnimationByDirection(eDirection dir)
	{
		switch (dir)
		{
		case JB::CatScript::eDirection::Left:
			mAnimator->PlayAnimation(L"LeftWalk", true);
			break;
		case JB::CatScript::eDirection::Right:
			mAnimator->PlayAnimation(L"RightWalk", true);
			break;
		case JB::CatScript::eDirection::Down:
			mAnimator->PlayAnimation(L"DownWalk", true);
			break;
		case JB::CatScript::eDirection::Up:
			mAnimator->PlayAnimation(L"UpWalk", true);
			break;
		default:
			assert(false);
			break;
		}
	}
	void CatScript::translate(Transform* tr)
	{
		Vector2 pos = tr->GetPosition();
		switch (mDirection)
		{
		case JB::CatScript::eDirection::Left:
			pos.x -= 100.0f * Time::DeltaTime();
			break;
		case JB::CatScript::eDirection::Right:
			pos.x += 100.0f * Time::DeltaTime();
			break;
		case JB::CatScript::eDirection::Down:
			pos.y += 100.0f * Time::DeltaTime();
			break;
		case JB::CatScript::eDirection::Up:
			pos.y -= 100.0f * Time::DeltaTime();
			break;
		default:
			assert(false);
			break;
		}
		tr->SetPosition(pos);
	}
}