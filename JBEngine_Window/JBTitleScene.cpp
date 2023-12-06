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

		// 타이틀 배경
		mBackground = object::Instantiate<Player>(enums::eLayerType::BackGround /*Vector2(100.0f, 100.0f)*/);
		SpriteRenderer* sr = mBackground->AddComponent<SpriteRenderer>();
		sr->SetSize(Vector2(2.0f, 2.0f));
		//mBackground->AddComponent<PlayerScript>();

		graphics::Texture* backgroundTexture = Resources::Find<graphics::Texture>(L"BG");
		sr->SetTexture(backgroundTexture);

		// 배경 구름1
		GameObject* cloud1 = object::Instantiate<GameObject>(enums::eLayerType::Cloud);
		cloud1->AddComponent<cloudScript>();

		graphics::Texture* cloudTexture = Resources::Find<graphics::Texture>(L"Cloud1");
		Animator* cloudAnimator = cloud1->AddComponent<Animator>();
		cloudAnimator->CreateAnimation(L"CloudMove1", cloudTexture
			, Vector2(0.0f, 0.0f), Vector2(132.0f, 60.0f), Vector2::Zero, 1, 2.0f);
		/*cloudAnimator->CreateAnimation(L"CloudMove2", cloudTexture
			, Vector2(0.0f, 0.0f), Vector2(132.0f, 60.0f), Vector2::Zero, 1, 0.1f);
		cloudAnimator->CreateAnimation(L"CloudMove3", cloudTexture
			, Vector2(0.0f, 0.0f), Vector2(132.0f, 60.0f), Vector2::Zero, 1, 0.1f);*/

		cloudAnimator->PlayAnimation(L"CloudMove1", false);

		cloud1->GetComponent<Transform>()->SetPosition(Vector2(100.0f, 100.0f));
		cloud1->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));


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
