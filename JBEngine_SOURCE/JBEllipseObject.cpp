#include "JBEllipseObject.h"
#include "JBInput.h"

namespace JB
{
	EllipseObject::EllipseObject()
	{
	}
	EllipseObject::~EllipseObject()
	{
	}
	void EllipseObject::Update()
	{
		if (Input::GetKey(eKeyCode::A))
		{
			mX -= 0.01f;
		}
		if (Input::GetKey(eKeyCode::D))
		{
			mX += 0.01f;
		}
		if (Input::GetKey(eKeyCode::W))
		{
			mY -= 0.01f;
		}
		if (Input::GetKey(eKeyCode::S))
		{
			mY += 0.01f;
		}
	}
	void EllipseObject::LateUpdate()
	{

	}
	void EllipseObject::Render(HDC hdc)
	{
		HBRUSH redBrush = CreateSolidBrush(RGB(255, 0, 0));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, redBrush);

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);

		SelectObject(hdc, oldPen);

		Ellipse(hdc, 100 + mX, 300 + mY, 200 + mX, 400 + mY);

		SelectObject(hdc, oldBrush);
		DeleteObject(redPen);
		DeleteObject(redBrush);
	}
}
