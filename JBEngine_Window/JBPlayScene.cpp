#include "JBPlayScene.h"
#include "JBGameObject.h"
#include "JBPlayer.h"
#include "JBTransform.h"
#include "JBSpriteRenderer.h"

namespace JB
{
	PlayScene::PlayScene()
	{
	}
	PlayScene::~PlayScene()
	{
	}

	void PlayScene::Initialize()
	{
		/*for (size_t i = 0; i < 100; i++)
		{
			GameObject* obj = new GameObject();
			obj->SetPosition(rand() % 1600, rand() % 900);
			AddGameObject(obj);
		}*/
		Player* p1 = new Player();
		Transform* tr = p1->AddComponent<Transform>();
		tr->SetPos(Vector2(800, 450));
		tr->SetName(L"TR");

		SpriteRenderer* sr = p1->AddComponent<SpriteRenderer>();
		sr->SetName(L"SR");

		AddGameObject(p1);
	}

	void PlayScene::Update()
	{
		// 부모의 함수를 호출(풀네임으로)
		Scene::Update();
		/*for (GameObject* gameObj : mGameObjects)
		{
			gameObj->Update();
		}*/
	}

	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();
	}

	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}
