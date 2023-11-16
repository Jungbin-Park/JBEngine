#include "JBSpriteRenderer.h"
#include "JBGameObject.h"
#include "JBTransform.h"

JB::SpriteRenderer::SpriteRenderer()
{
}

JB::SpriteRenderer::~SpriteRenderer()
{
}


void JB::SpriteRenderer::Initialize()
{
	mImage = Gdiplus::Image::FromFile(L"C:\\C++\\JBEngine\\Resources\\CloudOcean.png");
}

void JB::SpriteRenderer::Update()
{

}

void JB::SpriteRenderer::LateUpdate()
{

}

void JB::SpriteRenderer::Render(HDC hdc)
{
	/*HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);

	HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	HPEN oldPen = (HPEN)SelectObject(hdc, redPen);

	SelectObject(hdc, oldPen);*/

	Transform* tr = GetOwner()->GetComponent<Transform>();
	Vector2 pos = tr->GetPos();
	/*Rectangle(hdc, tr->GetPos().x, tr->GetPos().y, 200 + tr->GetPos().x, 400 + tr->GetPos().y);

	SelectObject(hdc, oldBrush);
	DeleteObject(redPen);
	DeleteObject(blueBrush);*/

	Gdiplus::Graphics graphics(hdc);
	graphics.TranslateTransform(pos.x, pos.y);
	graphics.RotateTransform(0);
	graphics.TranslateTransform(-pos.x, -pos.y);
	graphics.DrawImage(mImage, Gdiplus::Rect(0, 0, 1500, 1040), );
}
