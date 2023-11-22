#pragma once
#include "JBEntity.h"
#include "JBGameObject.h"
#include "JBLayer.h"

namespace JB
{
	class Scene : public Entity
	{
	public:
		Scene();
		~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		virtual void OnEnter();
		virtual void OnExit();

		void AddGameObject(GameObject* gameObj, const eLayerType type);

	private:
		void createLayers();

	private:
		std::vector<Layer*> mLayers;
	};
}


