#include "JBFarmhouseScene.h"
#include "JBGameObject.h"
#include "JBPlayer.h"
#include "JBTransform.h"
#include "JBSpriteRenderer.h"
#include "JBInput.h"
#include "JBTitleScene.h"
#include "JBSceneManager.h"
#include "JBObject.h"
#include "JBTexture.h"
#include "JBResources.h"
#include "JBPlayerScript.h"
#include "JBCamera.h"
#include "JBRenderer.h"

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
		// 카메라
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None, Vector2(600.0f, 450.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;

		// 플레이어
		mPlayer = object::Instantiate<Player>(enums::eLayerType::Player /*Vector2(100.0f, 100.0f)*/);
		SpriteRenderer* sr = mPlayer->AddComponent<SpriteRenderer>();
		sr->SetSize(Vector2(3.0f, 3.0f));
		mPlayer->AddComponent<PlayerScript>();

		graphics::Texture* backgroundTexture = Resources::Find<graphics::Texture>(L"Player");
		sr->SetTexture(backgroundTexture);

		// 배경
		GameObject* farmhouseBg = object::Instantiate<GameObject>
			(enums::eLayerType::BackGround);
		SpriteRenderer* bgSr = farmhouseBg->AddComponent<SpriteRenderer>();
		bgSr->SetSize(Vector2(3.0f, 3.0f));

		graphics::Texture* farmhouseTexture = Resources::Find<graphics::Texture>(L"Farmhouse");
		bgSr->SetTexture(farmhouseTexture);

		//  게임 오브젝트 생성 후에 레이어와 게임 오브젝트들의 init함수를 호출
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

		/*wchar_t str[50] = L"Farmhouse Scene";
		TextOut(hdc, 0, 0, str, 15);*/
	}
	void FarmhouseScene::OnEnter()
	{
	}
	void FarmhouseScene::OnExit()
	{
	}
}
