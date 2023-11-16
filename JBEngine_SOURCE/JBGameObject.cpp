#include "JBGameObject.h"
#include "JBInput.h"
#include "JBTime.h"


namespace JB
{
	GameObject::GameObject()
		: mX(0), mY(0)
	{
	}
	GameObject::~GameObject()
	{
	}
	void GameObject::Initialize()
	{
	}
	void GameObject::Update()
	{
		const int speed = 100.0f;
		if (Input::GetKey(eKeyCode::A))
		{
			mX -= speed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::D))
		{
			mX += speed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::W))
		{
			mY -= speed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::S))
		{
			mY += speed * Time::DeltaTime();
		}
	}
	void GameObject::LateUpdate()
	{

	}
	void GameObject::Render(HDC hdc)
	{
		HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);

		SelectObject(hdc, oldPen);

		Rectangle(hdc, 100 + mX, 300 + mY, 200 + mX, 400 + mY);

		SelectObject(hdc, oldBrush);
		DeleteObject(redPen);
		DeleteObject(blueBrush);
	}
}
