#pragma once
#include "..\\JBEngine_SOURCE\JBScene.h"

namespace JB
{
	class FarmhouseScene : public Scene
	{
	public:
		FarmhouseScene();
		~FarmhouseScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnEnter() override;
		void OnExit() override;

	private:
		class Player* mPlayer;
		class Camera* mCameraComp;
	};
}


