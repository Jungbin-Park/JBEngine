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
		// ī�޶�
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None, Vector2(600.0f, 450.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;

		// �÷��̾�
		mPlayer = object::Instantiate<Player>(enums::eLayerType::Player /*Vector2(100.0f, 100.0f)*/);
		SpriteRenderer* sr = mPlayer->AddComponent<SpriteRenderer>();
		sr->SetSize(Vector2(3.0f, 3.0f));
		mPlayer->AddComponent<PlayerScript>();

		graphics::Texture* backgroundTexture = Resources::Find<graphics::Texture>(L"Player");
		sr->SetTexture(backgroundTexture);

		// ���ȭ��
		GameObject* town = object::Instantiate<GameObject>
			(enums::eLayerType::BackGround);
		SpriteRenderer* townSr = town->AddComponent<SpriteRenderer>();
		townSr->SetSize(Vector2(3.0f, 3.0f));

		graphics::Texture* townTexture = Resources::Find<graphics::Texture>(L"");
		townSr->SetTexture(townTexture);

		//  ���� ������Ʈ ���� �Ŀ� ���̾�� ���� ������Ʈ���� init�Լ��� ȣ��
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
			SceneManager::LoadScene(L"TitleScene");
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

	}
	void PlayScene::OnExit()
	{
		//Transform* tr = bg->GetComponent<Transform>();
		//tr->SetPosition(Vector2(0, 0));
	}
}
