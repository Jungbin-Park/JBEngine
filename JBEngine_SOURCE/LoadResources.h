#pragma once
#include "..\\JBEngine_SOURCE\\JBResources.h"
#include "..\\JBEngine_SOURCE\\JBTexture.h"

namespace JB
{
	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"BG", L"C:\\C++\\JBEngine\\Resources\\CloudOcean.png");
		Resources::Load<graphics::Texture>(L"LOGO", L"C:\\C++\\JBEngine\\Resources\\logo.png");
		Resources::Load<graphics::Texture>(L"Town", L"C:\\C++\\JBEngine\\Resources\\PelicanTown.png");
		Resources::Load<graphics::Texture>(L"Farmhouse", L"C:\\C++\\JBEngine\\Resources\\Farmhouse.png");
		Resources::Load<graphics::Texture>(L"Player", L"C:\\C++\\JBEngine\\Resources\\Player.png");
	}
}