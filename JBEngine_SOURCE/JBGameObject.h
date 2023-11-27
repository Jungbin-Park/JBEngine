#pragma once
#include "CommonInclude.h"
#include "JBComponent.h"

namespace JB
{
	class GameObject
	{
	public:
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

	private:
		void initializeTransform();

	private:
		std::vector<Component*> mComponents;

	};
}
