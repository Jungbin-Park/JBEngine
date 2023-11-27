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
		// ī�޶�
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None, Vector2(600.0f, 450.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;

		// Ÿ��Ʋ ���
		mBackground = object::Instantiate<Player>(enums::eLayerType::BackGround /*Vector2(100.0f, 100.0f)*/);
		SpriteRenderer* sr = mBackground->AddComponent<SpriteRenderer>();
		sr->SetSize(Vector2(1.0f, 1.0f));
		//mBackground->AddComponent<PlayerScript>();

		graphics::Texture* backgroundTexture = Resources::Find<graphics::Texture>(L"BG");
		sr->SetTexture(backgroundTexture);

		// Ÿ��Ʋ �ΰ�
		GameObject* logo = object::Instantiate<GameObject>
			(enums::eLayerType::Logo, Vector2(250.0f, 225.0f));
		SpriteRenderer* bgSr = logo->AddComponent<SpriteRenderer>();
		bgSr->SetSize(Vector2(1.0f, 1.0f));

		graphics::Texture* logoTexture = Resources::Find<graphics::Texture>(L"LOGO");
		bgSr->SetTexture(logoTexture);

		//  ���� ������Ʈ ���� �Ŀ� ���̾�� ���� ������Ʈ���� init�Լ��� ȣ��
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