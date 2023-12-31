#pragma once
#include "CommonInclude.h"
#include "JBComponent.h"
#include "JBCollider.h"

namespace JB::object
{
	void Destroy(GameObject* gameObject);
}

namespace JB
{
	class GameObject
	{
	public:
		friend void object::Destroy(GameObject* obj);
		//friend Component;

		enum class eState
		{
			Active,
			Paused,
			Dead,
			End,
		};

		GameObject();
		~GameObject();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		template<typename T>
		T* AddComponent()
		{
			T* comp = new T();
			comp->Initialize();
			comp->SetOwner(this);

			mComponents[(UINT)comp->GetType()] = comp;

			return comp;
		}

		template<typename T>
		T* GetComponent()
		{
			T* comp = nullptr;
			for (Component* component : mComponents)
			{
				comp = dynamic_cast<T*>(component);
				if (comp)
					break;
			}
			return comp;
		}

		eState GetState() { return mState; }
		void SetActive(bool power)
		{
			if (power == true) mState = eState::Active;
			if (power == false) mState = eState::Paused;
		}
		bool IsActive() { return mState == eState::Active; }
		bool IsDead() { return mState == eState::Dead; }

		void SetLayerType(eLayerType layerType) { mLayerType = layerType; }
		eLayerType GetLayerType() { return mLayerType; }

	private:
		void initializeTransform();
		void death() { mState = eState::Dead; }

	private:
		eState mState;
		std::vector<Component*> mComponents;
		eLayerType mLayerType;
	};
}
