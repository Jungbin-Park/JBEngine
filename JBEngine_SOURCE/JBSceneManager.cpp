#include "JBSceneManager.h"

namespace JB
{
	std::map<std::wstring, Scene*> SceneManager::mScene = {};
	Scene* SceneManager::mActiveScene = nullptr;

	Scene* SceneManager::LoadScene(const std::wstring& name)
	{
		//  ���� �� OnExit() ȣ��
		if (mActiveScene)
			mActiveScene->OnExit();

		std::map<std::wstring, Scene*>::iterator iter
			= mScene.find(name);

		if (iter == mScene.end())
			return nullptr;

		mActiveScene = iter->second;
		// ���� OnEnterȣ��
		mActiveScene->OnEnter();

		return iter->second;
	}

	void SceneManager::Initialize()
	{

	}

	void SceneManager::Update()
	{
		mActiveScene->Update();
	}

	void SceneManager::LateUpdate()
	{
		mActiveScene->LateUpdate();
	}

	void SceneManager::Render(HDC hdc)
	{
		mActiveScene->Render(hdc);
	}
}