#include "JBFarmhouseScene.h"
#include "JBGameObject.h"
#include "JBPlayer.h"
#include "JBTransform.h"
#include "JBSpriteRenderer.h"

namespace JB
{
	FarmhouseScene::FarmhouseScene()
	{
	}
	FarmhouseScene::~FarmhouseScene()
	{
	}

	void FarmhouseScene::Initialize()
	{
		Player* bg = new Player();
		Transform* tr = bg->AddComponent<Transform>();
		tr->SetPos(Vector2(0, 0));
		tr->SetName(L"TR");

		SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
		sr->SetName(L"SR");
		sr->ImageLoad(L"C:\\C++\\JBEngine\\Resources\\Farmhouse.png");

		AddGameObject(bg);
	}

	void FarmhouseScene::Update()
	{
		Scene::Update();
	}

	void FarmhouseScene::LateUpdate()
	{
		Scene::LateUpdate();
	}

	void FarmhouseScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}
