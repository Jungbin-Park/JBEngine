#pragma once
#include "JBScene.h"

namespace JB
{
	class SceneManager
	{
	public:
		template <typename T>
		static Scene* CreateScene(const std::wstring& name)
		{
			T* scene = new T();
			scene->SetName(name);
			scene->Initialize();

			mScene.insert(std::make_pair(name, scene));

			return scene;
		}
		static Scene* LoadScene(const std::wstring& name)
		{
			//  나올 때 OnExit() 호출
			if (mActiveScene)
				mActiveScene->OnExit();

			std::map<std::wstring, Scene*>::iterator iter
				= mScene.find(name);

			if (iter == mScene.end())
				return nullptr;

			mActiveScene = iter->second;
			// 들어가고 OnEnter호출
			mActiveScene->OnEnter();

			return iter->second;
		}

		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);

	private:
		//static std::vector<Scene*> mScene;
		static std::map<std::wstring, Scene*> mScene;
		static Scene* mActiveScene;
	};
}


