#include "JBCameraScript.h"
#include "JBInput.h"
#include "JBTransform.h"
#include "JBTime.h"
#include "JBGameObject.h"
#include "JBAnimation.h"
#include "JBCat.h"
#include "JBCatScript.h"
#include "JBObject.h"
#include "JBResources.h"

namespace JB
{
	CameraScript::CameraScript()
	{
	}

	CameraScript::~CameraScript()
	{
	}

	void CameraScript::Initialize()
	{
	}

	void CameraScript::Update()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (Input::GetKey(eKeyCode::Right))
		{
			pos.x += 100.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::Left))
		{
			pos.x -= 100.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::Up))
		{
			pos.y -= 100.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::Down))
		{
			pos.y += 100.0f * Time::DeltaTime();
		}

		tr->SetPosition(pos);
	}

	void CameraScript::LateUpdate()
	{
	}

	void CameraScript::Render(HDC hdc)
	{
	}
}