#pragma once
#include "JBScene.h"

namespace JB
{
	class SceneManager
	{
	public:
		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);

	private:
		static std::vector<Scene*> mScene;
		static Scene* mActiveScene;
	};
}


