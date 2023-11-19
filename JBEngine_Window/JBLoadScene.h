#pragma once
#include "..\\JBEngine_SOURCE\JBSceneManager.h"
#include "JBPlayScene.h"
#include "JBTitleScene.h"
#include "JBFarmhouseScene.h"

namespace JB
{
	void LoadScenes()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		//SceneManager::CreateScene<EndScene>(L"EndScene");
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<FarmhouseScene>(L"FarmhouseScene");

		//SceneManager::LoadScene(L"PlayScene");
		//SceneManager::LoadScene(L"TitleScene");
		SceneManager::LoadScene(L"FarmhouseScene");
	}
}
