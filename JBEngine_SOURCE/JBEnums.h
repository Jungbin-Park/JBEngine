#pragma once

namespace JB::enums
{
	enum class eComponentType
	{
		Transform,
		SpriteRenderer,
		Script,
		Animator,
		Camera,
		End,
	};

	enum class eLayerType
	{
		None,
		BackGround,
		Cloud,
		Logo,
		//Tree
		//character
		Animal,
		Player,
		Particle,
		Max = 16,
	};

	enum class eResourceType
	{
		Texture,
		AudioClip,
		Animation,
		Prefab,
		End,
	};
}