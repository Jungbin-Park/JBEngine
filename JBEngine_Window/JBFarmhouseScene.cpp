#include "JBFarmhouseScene.h"
#include "JBGameObject.h"
#include "JBPlayer.h"
#include "JBTransform.h"
#include "JBSpriteRenderer.h"
#include "JBInput.h"
#include "JBTitleScene.h"
#include "JBSceneManager.h"
#include "JBObject.h"

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
		bg = object::Instantiate<Player>(enums::eLayerType::BackGround, Vector2(100.0f, 100.0f));
		SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
		sr->ImageLoad(L"C:\\C++\\JBEngine\\Resources\\Farmhouse.png");

		//  ���� ������Ʈ ���� �Ŀ� ���̾�� ���� ������Ʈ���� init�Լ��� ȣ��
		Scene::Initialize();
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

		wchar_t str[50] = L"Farmhouse Scene";
		TextOut(hdc, 0, 0, str, 15);
	}
	void FarmhouseScene::OnEnter()
	{
	}
	void FarmhouseScene::OnExit()
	{
	}
}
