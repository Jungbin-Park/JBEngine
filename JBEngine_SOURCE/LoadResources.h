#pragma once
#include "..\\JBEngine_SOURCE\\JBResources.h"
#include "..\\JBEngine_SOURCE\\JBTexture.h"

namespace JB
{
	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"BG", L"C:\\C++\\JBEngine\\Resources\\CloudOcean.png");
		Resources::Load<graphics::Texture>(L"LOGO", L"C:\\C++\\JBEngine\\Resources\\logo.png");
	}
}