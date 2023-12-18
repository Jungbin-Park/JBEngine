#pragma once
#include "JBComponent.h"
#include "JBGameObject.h"
#include "JBLayer.h"
#include "JBScene.h"
#include "JBSceneManager.h"
#include "JBTransform.h"

namespace JB::object
{
	template <typename T>
	static T* Instantiate(JB::enums::eLayerType type)
	{
		T* gameObject = new T();
		gameObject->SetLayerType(type);
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		return gameObject;
	}

	template <typename T>
	static T* Instantiate(JB::enums::eLayerType type, math::Vector2 position)
	{
		T* gameObject = new T();
		gameObject->SetLayerType(type);
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		Transform* tr = gameObject->GetComponent<Transform>();
		tr->SetPosition(position);

		return gameObject;
	}

	static void DontDestroyOnLoad(GameObject* gameObject)
	{
		Scene* activeScene = SceneManager::GetActiveScene();
		// 현재 씬에서 게임 오브젝트를 지워준다.
		activeScene->EraseGameObject(gameObject);

		// 해당 게임 오브젝트를 Dontdestroy씬으로 넘겨준다.
		Scene* dontDestroyOnLoad = SceneManager::GetDontDestroyOnLoad();
		dontDestroyOnLoad->AddGameObject(gameObject, gameObject->GetLayerType());
	}
}
