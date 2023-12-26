#include "JBPlayScene.h"
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
#include "JBBoxCollider2D.h"
#include "JBCollisionManager.h"
#include "JBTile.h"
#include "JBTilemapRenderer.h"

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
		FILE* pFile = nullptr;
		_wfopen_s(&pFile, L"..\\Resources\\Test", L"rb");

		while (true)
		{
			int idxX = 0;
			int idxY = 0;

			int posX = 0;
			int posY = 0;

			if (fread(&idxX, sizeof(int), 1, pFile) == NULL)
				break;
			if (fread(&idxY, sizeof(int), 1, pFile) == NULL)
				break;
			if (fread(&posX, sizeof(int), 1, pFile) == NULL)
				break;
			if (fread(&posY, sizeof(int), 1, pFile) == NULL)
				break;

			Tile* tile = object::Instantiate<Tile>(eLayerType::Tile);
			TilemapRenderer* tmr = tile->AddComponent<TilemapRenderer>();
			tmr->SetTexture(Resources::Find<graphics::Texture>(L"SpringFloor"));
			tmr->SetIndex(Vector2(idxX, idxY));
		}

		fclose(pFile);
	

		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Animal, true);

		/// 카메라
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None, Vector2(640.0f, 360.0f));
		mCameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = mCameraComp;


		/// 배경화면
		GameObject* town = object::Instantiate<GameObject>
			(enums::eLayerType::BackGround);
		SpriteRenderer* townSr = town->AddComponent<SpriteRenderer>();
		townSr->SetSize(Vector2(3.0f, 3.0f));

		graphics::Texture* townTexture = Resources::Find<graphics::Texture>(L"Town");
		townSr->SetTexture(townTexture);


		/// 플레이어
		mPlayer = object::Instantiate<Player>(enums::eLayerType::Player /*Vector2(100.0f, 100.0f)*/);
		
		PlayerScript* plScript = mPlayer->AddComponent<PlayerScript>();

		// Collider
		BoxCollider2D* collider = mPlayer->AddComponent<BoxCollider2D>();
		//CircleCollider2D* circleCollider = mPlayer->AddComponent<CircleCollider2D>();
		collider->SetOffset(Vector2(-50.0f, -50.0f));

		graphics::Texture* playerTexture = Resources::Find<graphics::Texture>(L"Player");
		graphics::Texture* playerPickTexture = Resources::Find<graphics::Texture>(L"PlayerPick");
		graphics::Texture* playerDownWalkTexture = Resources::Find<graphics::Texture>(L"PlayerDownWalk");
		Animator* playerAnimator = mPlayer->AddComponent<Animator>();

		// Idle
		playerAnimator->CreateAnimation(L"UpIdle", playerTexture
			, Vector2(0.0f, 250.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 1, 0.1f);
		playerAnimator->CreateAnimation(L"DownIdle", playerTexture
			, Vector2(2000.0f, 250.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 1, 0.1f);
		playerAnimator->CreateAnimation(L"LeftIdle", playerTexture
			, Vector2(1500.0f, 0.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 1, 0.1f);
		playerAnimator->CreateAnimation(L"RightIdle", playerTexture
			, Vector2(0.0f, 0.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 1, 0.1f);
		// Walk
		playerAnimator->CreateAnimation(L"UpWalk", playerTexture
			, Vector2(0.0f, 250.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 8, 0.1f);
		playerAnimator->CreateAnimation(L"DownWalk", playerTexture
			, Vector2(2000.0f, 250.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 7, 0.1f);
		playerAnimator->CreateAnimation(L"LeftWalk", playerTexture
			, Vector2(1500.0f, 0.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 6, 0.1f);
		playerAnimator->CreateAnimation(L"RightWalk", playerTexture
			, Vector2(0.0f, 0.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 6, 0.1f);
		// GiveWater
		playerAnimator->CreateAnimation(L"UpGiveWater", playerTexture
			, Vector2(1250.0f, 2250.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 5, 0.1f);
		playerAnimator->CreateAnimation(L"DownGiveWater", playerTexture
			, Vector2(0.0f, 2000.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 12, 0.05f);
		playerAnimator->CreateAnimation(L"LeftGiveWater", playerTexture
			, Vector2(0.0f, 2250.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 5, 0.1f);
		playerAnimator->CreateAnimation(L"RightGiveWater", playerTexture
			, Vector2(1500.0f, 1750.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 5, 0.1f);
		// Attack
		playerAnimator->CreateAnimation(L"UpAttack", playerTexture
			, Vector2(1500.0f, 3250.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 3, 0.1f);
		playerAnimator->CreateAnimation(L"DownAttack", playerTexture
			, Vector2(0.0f, 3000.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 6, 0.1f);
		playerAnimator->CreateAnimation(L"LeftAttack", playerTexture
			, Vector2(0.0f, 3250.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 6, 0.1f);
		playerAnimator->CreateAnimation(L"RightAttack", playerTexture
			, Vector2(1500.0f, 3000.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 6, 0.1f);
		// Axe
		playerAnimator->CreateAnimation(L"UpAxe", playerTexture
			, Vector2(1750.0f, 750.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 4, 0.1f);
		playerAnimator->CreateAnimation(L"DownAxe", playerTexture
			, Vector2(750.0f, 500.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 6, 0.1f);
		playerAnimator->CreateAnimation(L"LeftAxe", playerTexture
			, Vector2(500.0f, 750.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 5, 0.1f);
		playerAnimator->CreateAnimation(L"RightAxe", playerTexture
			, Vector2(2250.0f, 500.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 5, 0.1f);
		// Pick
		playerAnimator->CreateAnimation(L"UpPick", playerTexture
			, Vector2(1750.0f, 3500.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 5, 0.1f);
		playerAnimator->CreateAnimation(L"DownPick", playerTexture
			, Vector2(0.0f, 3500.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 7, 0.1f);
		playerAnimator->CreateAnimation(L"LeftPick", playerPickTexture
			, Vector2(0.0f, 250.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 5, 0.1f);
		playerAnimator->CreateAnimation(L"RightPick", playerTexture
			, Vector2(0.0f, 3750.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 5, 0.1f);
		// Sickle
		playerAnimator->CreateAnimation(L"UpSickle", playerTexture
			, Vector2(0.0f, 1750.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 6, 0.1f);
		playerAnimator->CreateAnimation(L"DownSickle", playerTexture
			, Vector2(1250.0f, 1250.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 6, 0.1f);
		playerAnimator->CreateAnimation(L"LeftSickle", playerTexture
			, Vector2(1500.0f, 1500.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 6, 0.1f);
		playerAnimator->CreateAnimation(L"RightSickle", playerTexture
			, Vector2(0.0f, 1500.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 6, 0.1f);


		playerAnimator->PlayAnimation(L"DownIdle", false);

			// 애니메이션 바인딩
		playerAnimator->GetCompleteEvent(L"DownGiveWater") = std::bind(&PlayerScript::WaterEvent, plScript);

		mPlayer->GetComponent<Transform>()->SetPosition(Vector2(500.0f, 300.0f));
		mPlayer->GetComponent<Transform>()->SetScale(Vector2(1.0f, 1.0f));


		// 카메라 타겟 고정
		mCameraComp->SetTarget(mPlayer);

		//sr->SetTexture(backgroundTexture);

		/// CAT
		Cat* cat = object::Instantiate<Cat>(enums::eLayerType::Animal);
		cat->AddComponent<CatScript>();

		graphics::Texture* catTex = Resources::Find<graphics::Texture>(L"Cat");
		Animator* catAnimator = cat->AddComponent<Animator>();

		BoxCollider2D* boxCatCollider = cat->AddComponent<BoxCollider2D>();

		boxCatCollider->SetOffset(Vector2(0.0f, 0.0f));

		catAnimator->CreateAnimation(L"DownWalk", catTex
			, Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catAnimator->CreateAnimation(L"RightWalk", catTex
			, Vector2(0.0f, 32.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catAnimator->CreateAnimation(L"UpWalk", catTex
			, Vector2(0.0f, 64.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catAnimator->CreateAnimation(L"LeftWalk", catTex
			, Vector2(0.0f, 96.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catAnimator->CreateAnimation(L"SitDown", catTex
			, Vector2(0.0f, 128.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catAnimator->CreateAnimation(L"Grooming", catTex
			, Vector2(0.0f, 160.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catAnimator->CreateAnimation(L"LayDown", catTex
			, Vector2(0.0f, 192.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);

		catAnimator->PlayAnimation(L"SitDown", false);

		cat->GetComponent<Transform>()->SetPosition(Vector2(200.0f, 200.0f));
		cat->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));

		


		//  게임 오브젝트 생성 후에 레이어와 게임 오브젝트들의 init함수를 호출
		Scene::Initialize();
	}

	void PlayScene::Update()
	{
		Scene::Update();
	}

	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(L"FarmhouseScene");
		}
	}

	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		/*wchar_t str[50] = L"Play Scene";
		TextOut(hdc, 0, 0, str, 10);*/
	}
	void PlayScene::OnEnter()
	{
		renderer::mainCamera = mCameraComp;

		Scene::OnEnter();
		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Animal, true);
	}
	void PlayScene::OnExit()
	{
		Scene::OnExit();
		//Transform* tr = bg->GetComponent<Transform>();
		//tr->SetPosition(Vector2(0, 0));
	}
}
