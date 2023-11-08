#include "JBEllipseObject.h"


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
		if (GetAsyncKeyState('A') & 0x8000)
		{
			mX -= 0.01f;
		}
		if (GetAsyncKeyState('D') & 0x8000)
		{
			mX += 0.01f;
		}
		if (GetAsyncKeyState('W') & 0x8000)
		{
			mY -= 0.01f;
		}
		if (GetAsyncKeyState('S') & 0x8000)
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
