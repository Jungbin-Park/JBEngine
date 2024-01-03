#pragma once
#include "JBEntity.h"

namespace JB
{
	using namespace enums;
	class UIBase : public Entity
	{
	public:
		struct Event
		{
			void operator=(std::function<void()> func)
			{
				mEvent = std::move(func);
			}
			void operator()()
			{
				if (mEvent)
					mEvent();
			}
			std::function<void()> mEvent;
		};

		UIBase(eUIType type);
		virtual ~UIBase();

		/// <summary>
		/// UI가 로드되었을 때 초기화 해주는 함수
		/// </summary>
		void Initialize();

		/// <summary>
		/// UI가 활성화되면 호출되는 함수
		/// </summary>
		void Active();

		/// <summary>
		/// UI가 비활성화되면 호출되는 함수
		/// </summary>
		/// <returns></returns>
		void InActive();

		void Update();
		void LateUpdate();
		void Render(HDC hdc);

		/// <summary>
		/// UI가 사라질 때 호출되는 함수
		/// </summary>
		void UIClear();

		virtual void OnInit();
		virtual void OnActive();
		virtual void OnInActive();
		virtual void OnUpdate();
		virtual void OnLateUpdate();
		virtual void OnRender(HDC hdc);
		virtual void OnClear();
		

		eUIType GetType() { return mType; }
		void SetType(eUIType type) { mType = type; }
		void SetFullScreen(bool enable) { mbFullScreen = enable; }
		bool IsFullScreen() { return mbFullScreen; }
		Vector2 GetPos() { return mPosition; }
		void SetPos(Vector2 position) { mPosition = position; }
		Vector2 GetSize() { return mSize; }
		void SetSize(Vector2 size) { mSize = size; }

	protected:
		Vector2 mPosition;
		Vector2 mSize;
		bool mbMouseOn;

	private:
		eUIType mType;
		bool mbFullScreen;
		bool mbEnabled;

		UIBase* mParent;
	};
}


