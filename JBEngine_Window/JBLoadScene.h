#pragma once
#include "..\\JBEngine_SOURCE\JBSceneManager.h"
#include "JBPlayScene.h"

namespace JB
{
	void LoadScenes()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		//SceneManager::CreateScene<EndScene>(L"EndScene");
		//SceneManager::CreateScene<TitleScene>(L"TitleScene");

		SceneManager::LoadScene(L"PlayScene");
	}
}
