#include "JBMineScene.h"
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

namespace JB
{
	MineScene::MineScene()
	{
	}
	MineScene::~MineScene()
	{
	}
	void MineScene::Initialize()
	{
		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Animal, true);

		/// ī�޶�
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None, Vector2(640.0f, 360.0f));
		mCameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = mCameraComp;

		/// ���ȭ��
		GameObject* mine = object::Instantiate<GameObject>
			(enums::eLayerType::BackGround/*, Vector2(100.0f, 100.0f)*/);
		SpriteRenderer* mineSr = mine->AddComponent<SpriteRenderer>();
		mineSr->SetSize(Vector2(2.0f, 2.0f));

		graphics::Texture* mineTexture = Resources::Find<graphics::Texture>(L"Mine");
		mineSr->SetTexture(mineTexture);

		/// �÷��̾�
		mPlayer = object::Instantiate<Player>(enums::eLayerType::Player /*Vector2(100.0f, 100.0f)*/);
		PlayerScript* plScript = mPlayer->AddComponent<PlayerScript>();

		BoxCollider2D* collider = mPlayer->AddComponent<BoxCollider2D>();
		collider->SetOffset(Vector2(-85.0f, -85.0f));

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
		playerAnimator->CreateAnimation(L"DownWalk", playerDownWalkTexture
			, Vector2(0.0f, 0.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 7, 0.1f);
		playerAnimator->CreateAnimation(L"LeftWalk", playerTexture
			, Vector2(1500.0f, 0.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 6, 0.1f);
		playerAnimator->CreateAnimation(L"RightWalk", playerTexture
			, Vector2(0.0f, 0.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 6, 0.1f);
		// GiveWater
		playerAnimator->CreateAnimation(L"UpGiveWater", playerTexture
			, Vector2(1250.0f, 2250.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 3, 0.1f);
		playerAnimator->CreateAnimation(L"DownGiveWater", playerTexture
			, Vector2(0.0f, 2000.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 12, 0.1f);
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
		playerAnimator->CreateAnimation(L"Upsickle", playerTexture
			, Vector2(0.0f, 1750.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 6, 0.1f);
		playerAnimator->CreateAnimation(L"Downsickle", playerTexture
			, Vector2(1250.0f, 1250.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 6, 0.1f);
		playerAnimator->CreateAnimation(L"Leftsickle", playerTexture
			, Vector2(1500.0f, 1500.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 6, 0.1f);
		playerAnimator->CreateAnimation(L"Rightsickle", playerTexture
			, Vector2(0.0f, 1500.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 6, 0.1f);
		
		playerAnimator->PlayAnimation(L"DownIdle", false);

		// �ִϸ��̼� ���ε�
		playerAnimator->GetCompleteEvent(L"DownGiveWater") = std::bind(&PlayerScript::WaterEvent, plScript);

		mPlayer->GetComponent<Transform>()->SetPosition(Vector2(100.0f, 100.0f));
		mPlayer->GetComponent<Transform>()->SetScale(Vector2(1.0f, 1.0f));


		// ī�޶� Ÿ�� ����
		mCameraComp->SetTarget(mPlayer);


		Scene::Initialize();
	}
	void MineScene::Update()
	{
		Scene::Update();
	}
	void MineScene::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void MineScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
	void MineScene::OnEnter()
	{
		renderer::mainCamera = mCameraComp;
	}
	void MineScene::OnExit()
	{
	}
}