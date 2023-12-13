#pragma once
#include "..\\JBEngine_SOURCE\JBSceneManager.h"
#include "JBPlayScene.h"
#include "JBTitleScene.h"
#include "JBFarmhouseScene.h"
#include "JBMineScene.h"

namespace JB
{
	void LoadScenes()
	{
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		SceneManager::CreateScene<FarmhouseScene>(L"FarmhouseScene");
		SceneManager::CreateScene<MineScene>(L"MineScene");
		//SceneManager::CreateScene<EndScene>(L"EndScene");

		SceneManager::LoadScene(L"TitleScene");
		//SceneManager::LoadScene(L"PlayScene");
		//SceneManager::LoadScene(L"FarmhouseScene");
	}
}
