#include "JBcloudScript.h"
#include "JBInput.h"
#include "JBTransform.h"
#include "JBTime.h"
#include "JBGameObject.h"
#include "JBAnimator.h"
#include "JBObject.h"

JB::cloudScript::cloudScript()
	: mAnimator(nullptr)
{
}

JB::cloudScript::~cloudScript()
{
}

void JB::cloudScript::Initialize()
{
}

void JB::cloudScript::Update()
{
	if (mAnimator == nullptr)
	{
		mAnimator = GetOwner()->GetComponent<Animator>();
	}

	move();
}

void JB::cloudScript::LateUpdate()
{
}

void JB::cloudScript::Render(HDC hdc)
{
}

void JB::cloudScript::move()
{
	Transform* tr = GetOwner()->GetComponent<Transform>();
	translate(tr);
}

void JB::cloudScript::translate(Transform* tr)
{
	
	Vector2 pos = tr->GetPosition();
	if (pos.x > 1400)
	{
		pos.x = -132.0f;
	}

	pos.x += 10.0f * Time::DeltaTime();
	tr->SetPosition(pos);
}
