#pragma once
#include "..\\JBEngine_SOURCE\\JBResources.h"
#include "..\\JBEngine_SOURCE\\JBTexture.h"

namespace JB
{
	void LoadResources()
	{
		// ���
		Resources::Load<graphics::Texture>(L"BG", L"C:\\C++\\JBEngine\\Resources\\stardewPanorama.png");
		//Resources::Load<graphics::Texture>(L"LOGO", L"C:\\C++\\JBEngine\\Resources\\Logo.png");
		Resources::Load<graphics::Texture>(L"Logo", L"C:\\C++\\JBEngine\\Resources\\TitleButtons.bmp");
		Resources::Load<graphics::Texture>(L"Cloud1", L"C:\\C++\\JBEngine\\Resources\\cloud1.bmp");


		// ��
		Resources::Load<graphics::Texture>(L"Town", L"C:\\C++\\JBEngine\\Resources\\PelicanTown.png");
		Resources::Load<graphics::Texture>(L"Farmhouse", L"C:\\C++\\JBEngine\\Resources\\Farmhouse.png");

		// �÷��̾�
		Resources::Load<graphics::Texture>(L"Player", L"C:\\C++\\JBEngine\\Resources\\Player.bmp");

		// ����
		Resources::Load<graphics::Texture>(L"Cat", L"C:\\C++\\JBEngine\\Resources\\CatAlpha.bmp");
	}
}