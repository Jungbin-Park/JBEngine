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
#include "JBAnimator.h"
#include "JBCat.h"
#include "JBCatScript.h"

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
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None, Vector2(640.0f, 360.0f));
		mCameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = mCameraComp;

		/// 플레이어
		mPlayer = object::Instantiate<Player>(enums::eLayerType::Player /*Vector2(100.0f, 100.0f)*/);
		PlayerScript* plScript = mPlayer->AddComponent<PlayerScript>();

		graphics::Texture* playerTexture = Resources::Find<graphics::Texture>(L"Player");
		Animator* playerAnimator = mPlayer->AddComponent<Animator>();

		playerAnimator->CreateAnimation(L"Idle", playerTexture
			, Vector2(2000.0f, 250.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 1, 0.1f);
		playerAnimator->CreateAnimation(L"UpWalk", playerTexture
			, Vector2(0.0f, 250.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 8, 0.1f);
		playerAnimator->CreateAnimation(L"DownWalk", playerTexture
			, Vector2(2000.0f, 250.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 7, 0.1f);
		playerAnimator->CreateAnimation(L"LeftWalk", playerTexture
			, Vector2(1500.0f, 0.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 6, 0.1f);
		playerAnimator->CreateAnimation(L"RightWalk", playerTexture
			, Vector2(0.0f, 0.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 6, 0.1f);
		playerAnimator->CreateAnimation(L"FrontGiveWater", playerTexture
			, Vector2(0.0f, 2000.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 12, 0.1f);


		playerAnimator->PlayAnimation(L"Idle", false);

		// 애니메이션 바인딩
		playerAnimator->GetCompleteEvent(L"FrontGiveWater") = std::bind(&PlayerScript::WaterEvent, plScript);

		mPlayer->GetComponent<Transform>()->SetPosition(Vector2(100.0f, 100.0f));
		mPlayer->GetComponent<Transform>()->SetScale(Vector2(1.0f, 1.0f));

		mCameraComp->SetTarget(mPlayer);

		// 배경
		GameObject* farmhouseBg = object::Instantiate<GameObject>
			(enums::eLayerType::BackGround, Vector2(400.0f, 100.0f));
		SpriteRenderer* bgSr = farmhouseBg->AddComponent<SpriteRenderer>();
		bgSr->SetSize(Vector2(2.0f, 2.0f));

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

		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(L"MineScene");
		}
	}

	void FarmhouseScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		/*wchar_t str[50] = L"Farmhouse Scene";
		TextOut(hdc, 0, 0, str, 15);*/
	}
	void FarmhouseScene::OnEnter()
	{
		renderer::mainCamera = mCameraComp;
	}
	void FarmhouseScene::OnExit()
	{
	}
}
