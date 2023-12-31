#include "JBTitleScene.h"
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
#include "JBcloudScript.h"

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
		// 카메라
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None, Vector2(640.0f, 360.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;


		/// 배경화면
		GameObject* titleBg = object::Instantiate<GameObject>
			(enums::eLayerType::BackGround);
		SpriteRenderer* titleBgSr = titleBg->AddComponent<SpriteRenderer>();
		titleBgSr->SetSize(Vector2(2.0f, 2.0f));

		graphics::Texture* titleTexture = Resources::Find<graphics::Texture>(L"BG");
		titleBgSr->SetTexture(titleTexture);


		// 타이틀 로고
		GameObject* logo = object::Instantiate<GameObject>
			(enums::eLayerType::UI, Vector2(340.0f, 150.0f));
		SpriteRenderer* logoSr = logo->AddComponent<SpriteRenderer>();
		logoSr->SetSize(Vector2(1.5f, 1.5f));

		graphics::Texture* logoTexture = Resources::Find<graphics::Texture>(L"Logo");
		logoSr->SetTexture(logoTexture);

		// New 버튼
		GameObject* newButton = object::Instantiate<GameObject>(enums::eLayerType::UI);

		graphics::Texture* buttonTexture = Resources::Find<graphics::Texture>(L"Buttons");
		Animator* newButtonAnimator = newButton->AddComponent<Animator>();
		newButtonAnimator->CreateAnimation(L"NewButton", buttonTexture
			, Vector2(0.0f, 0.0f), Vector2(74.0f, 58.0f), Vector2::Zero, 1, 1.0f);

		newButtonAnimator->PlayAnimation(L"NewButton", false);

		newButton->GetComponent<Transform>()->SetPosition(Vector2(400.0f, 500.0f));
		newButton->GetComponent<Transform>()->SetScale(Vector2(1.5f, 1.5f));

		// Load 버튼
		GameObject* loadButton = object::Instantiate<GameObject>(enums::eLayerType::UI);

		Animator* loadButtonAnimator = loadButton->AddComponent<Animator>();
		loadButtonAnimator->CreateAnimation(L"LoadButton", buttonTexture
			, Vector2(74.0f, 0.0f), Vector2(74.0f, 58.0f), Vector2::Zero, 1, 1.0f);

		loadButtonAnimator->PlayAnimation(L"LoadButton", false);

		loadButton->GetComponent<Transform>()->SetPosition(Vector2(615.0f, 500.0f));
		loadButton->GetComponent<Transform>()->SetScale(Vector2(1.5f, 1.5f));

		// Exit 버튼
		GameObject* exitButton = object::Instantiate<GameObject>(enums::eLayerType::UI);

		Animator* exitButtonAnimator = exitButton->AddComponent<Animator>();
		exitButtonAnimator->CreateAnimation(L"ExitButton", buttonTexture
			, Vector2(222.0f, 0.0f), Vector2(74.0f, 58.0f), Vector2::Zero, 1, 1.0f);

		exitButtonAnimator->PlayAnimation(L"ExitButton", false);

		exitButton->GetComponent<Transform>()->SetPosition(Vector2(830.0f, 500.0f));
		exitButton->GetComponent<Transform>()->SetScale(Vector2(1.5f, 1.5f));



		// 배경 구름1
		GameObject* cloud1 = object::Instantiate<GameObject>(enums::eLayerType::Cloud);
		cloud1->AddComponent<cloudScript>();

		graphics::Texture* cloudTexture = Resources::Find<graphics::Texture>(L"Cloud1");
		Animator* cloudAnimator = cloud1->AddComponent<Animator>();
		cloudAnimator->CreateAnimation(L"CloudMove1", cloudTexture
			, Vector2(0.0f, 0.0f), Vector2(132.0f, 60.0f), Vector2::Zero, 1, 2.0f);

		cloudAnimator->PlayAnimation(L"CloudMove1", false);

		cloud1->GetComponent<Transform>()->SetPosition(Vector2(100.0f, 100.0f));
		cloud1->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));

		// 배경 구름2
		GameObject* cloud2 = object::Instantiate<GameObject>(enums::eLayerType::Cloud);
		cloud2->AddComponent<cloudScript>();

		graphics::Texture* cloud2Texture = Resources::Find<graphics::Texture>(L"Cloud1");
		Animator* cloud2Animator = cloud2->AddComponent<Animator>();
		cloud2Animator->CreateAnimation(L"CloudMove2", cloud2Texture
			, Vector2(0.0f, 0.0f), Vector2(132.0f, 60.0f), Vector2::Zero, 1, 2.0f);

		cloud2Animator->PlayAnimation(L"CloudMove2", false);

		cloud2->GetComponent<Transform>()->SetPosition(Vector2(700.0f, 200.0f));
		cloud2->GetComponent<Transform>()->SetScale(Vector2(3.0f, 3.0f));

		
		//  게임 오브젝트 생성 후에 레이어와 게임 오브젝트들의 init함수를 호출
		Scene::Initialize();
	}

	void TitleScene::Update()
	{
		Scene::Update();
	}

	void TitleScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(L"PlayScene");
		}
	}

	void TitleScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		/*wchar_t str[50] = L"Title Scene";
		TextOut(hdc, 0, 0, str, 11);*/
	}
	void TitleScene::OnEnter()
	{
	}
	void TitleScene::OnExit()
	{
	}
}
