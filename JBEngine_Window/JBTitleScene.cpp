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
		bg = object::Instantiate<Player>(enums::eLayerType::BackGround /*Vector2(100.0f, 100.0f)*/);
		SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
		graphics::Texture* bg = Resources::Find<graphics::Texture>(L"BG");
		sr->SetTexture(bg);
		/*bg = object::Instantiate<Player>(enums::eLayerType::BackGround, Vector2(0.0f, 0.0f));
		SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
		sr->ImageLoad(L"C:\\C++\\JBEngine\\Resources\\CloudOcean.png");

		logo = object::Instantiate<Player>(enums::eLayerType::Logo, Vector2(400.0f, 200.0f));
		SpriteRenderer* sr2 = logo->AddComponent<SpriteRenderer>();
		sr2->ImageLoad(L"C:\\C++\\JBEngine\\Resources\\Logo.png");*/

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

		wchar_t str[50] = L"Title Scene";
		TextOut(hdc, 0, 0, str, 11);
	}
	void TitleScene::OnEnter()
	{
	}
	void TitleScene::OnExit()
	{
	}
}
