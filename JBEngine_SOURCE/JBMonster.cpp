#include "JBMonster.h"

namespace JB
{
	float dir = 0.05f;
	int pathSum = 0;
	int path = 1;

	JBMonster::JBMonster()
	{

	}
	JBMonster::~JBMonster()
	{

	}
	void JBMonster::Update()
	{
		// 수정 필요
		pathSum += path;
		if (pathSum >= 300)
		{
			path *= -1;
			mY += dir;
		}
		else if (pathSum < 0)
		{
			path += -1;
			mX += dir;
		}
		else
		{
			path += -1;
			mX += dir;
		}

		if (mX < 0 || mX > 1200)
			dir *= -1;
		if (mY < 0 || mY > 300)
			dir *= -1;
		
	}
	void JBMonster::LateUpdate()
	{

	}
	void JBMonster::Render(HDC hdc)
	{
		HBRUSH greenBrush = CreateSolidBrush(RGB(0, 255, 0));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, greenBrush);

		HPEN blackPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, blackPen);

		SelectObject(hdc, oldPen);

		Ellipse(hdc, 100 + mX, 300 + mY, 150 + mX, 350 + mY);

		SelectObject(hdc, oldBrush);
		DeleteObject(blackPen);
		DeleteObject(greenBrush);
	}
}
