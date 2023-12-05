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

		// 타이틀 배경
		mBackground = object::Instantiate<Player>(enums::eLayerType::BackGround /*Vector2(100.0f, 100.0f)*/);
		SpriteRenderer* sr = mBackground->AddComponent<SpriteRenderer>();
		sr->SetSize(Vector2(2.0f, 2.0f));
		//mBackground->AddComponent<PlayerScript>();

		graphics::Texture* backgroundTexture = Resources::Find<graphics::Texture>(L"BG");
		sr->SetTexture(backgroundTexture);

		// 배경 구름
		GameObject* clouds = object::Instantiate<GameObject>(enums::eLayerType::Cloud);
		//SpriteRenderer* clSr = clouds->AddComponent<SpriteRenderer>();

		graphics::Texture* cloudTexture = Resources::Find<graphics::Texture>(L"Cloud");
		Animator* cloudAnimator = clouds->AddComponent<Animator>();

		cloudAnimator->CreateAnimation(L"CloudMove", cloudTexture
			, Vector2(128.0f, 406.0f), Vector2(128.0f, 58.0f), Vector2::Zero, 1, 0.1f);

		cloudAnimator->PlayAnimation(L"CloudMove", false);

		clouds->GetComponent<Transform>()->SetPosition(Vector2(100.0f, 100.0f));
		clouds->GetComponent<Transform>()->SetScale(Vector2(1.0f, 1.0f));


		// 타이틀 로고
		GameObject* logo = object::Instantiate<GameObject>
			(enums::eLayerType::Logo, Vector2(440.0f, 200.0f));
		SpriteRenderer* bgSr = logo->AddComponent<SpriteRenderer>();
		bgSr->SetSize(Vector2(1.0f, 1.0f));

		graphics::Texture* logoTexture = Resources::Find<graphics::Texture>(L"LOGO");
		bgSr->SetTexture(logoTexture);

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
