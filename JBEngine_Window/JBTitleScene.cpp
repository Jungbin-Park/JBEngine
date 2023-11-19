#include "JBTitleScene.h"
#include "JBGameObject.h"
#include "JBPlayer.h"
#include "JBTransform.h"
#include "JBSpriteRenderer.h"

namespace JB
{
	TitleScene::TitleScene()
	{
	}
	TitleScene::~TitleScene()
	{
	}

	void TitleScene::Initialize()
	{
		Player* bg = new Player();
		Transform* tr = bg->AddComponent<Transform>();
		tr->SetPos(Vector2(0, 0));
		tr->SetName(L"TR");

		SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
		sr->SetName(L"SR");
		sr->ImageLoad(L"C:\\C++\\JBEngine\\Resources\\CloudOcean.png");

		AddGameObject(bg);
	}

	void TitleScene::Update()
	{
		Scene::Update();
	}

	void TitleScene::LateUpdate()
	{
		Scene::LateUpdate();
	}

	void TitleScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}
