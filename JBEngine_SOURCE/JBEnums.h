#pragma once

namespace JB::enums
{
	enum class eLayerType
	{
		None,
		BackGround,
		Logo,
		//Tree
		//character
		Player,
		Max = 16,
	};

	enum class eResourceType
	{
		Texture,
		AudioClip,
		Prefab,
		End,
	};
}