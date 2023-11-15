#pragma once
#include "JBEntity.h"
#include "JBGameObject.h"

namespace JB
{
	class Scene : public Entity
	{
	public:
		Scene();
		~Scene();

	private:
		std::vector<GameObject*> mGameObjects;
	};
}


