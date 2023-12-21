#pragma once
#include "..\\JBEngine_SOURCE\\JBScript.h"
#include "..\\JBEngine_SOURCE\\JBTransform.h"

namespace JB
{
	class CameraScript : public Script
	{
	public:
		CameraScript();
		~CameraScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:

	};
}


