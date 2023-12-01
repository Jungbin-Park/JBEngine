#pragma once
#include "CommonInclude.h"

namespace JB 
{
	enum class eKeyState
	{
		Down,
		Pressed,
		Up,
		None,
	};

	enum class eKeyCode
	{
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M, 
		Left, Right, Down, Up,
		LButton, MButton, RButton,
		End,
	};

	class Input
	{
	public:
		struct Key
		{
			eKeyCode keyCode;	// 어떤 키
			eKeyState state;
			bool bPressed;	// 눌렸는지
		};

		static void Initialize();
		static void Update();

		static bool GetKeyDown(eKeyCode code) { return Keys[(UINT)code].state == eKeyState::Down; }
		static bool GetKeyUp(eKeyCode code) { return Keys[(UINT)code].state == eKeyState::Up; }
		static bool GetKey(eKeyCode code) { return Keys[(UINT)code].state == eKeyState::Pressed; }
		static math::Vector2 GetMousePosition() { return mMousePosition; }

	private:
		static void createKeys();
		static void updateKeys();
		static void updateKey(Input::Key& key);
		static bool isKeyDown(eKeyCode code);
		static void updateKeyDown(Input::Key& key);
		static void updateKeyUp(Input::Key& key);
		static void getMousePositionByWindow();
		static void clearKeys();

	private:
		//eKeyState mState[] = eKeyState::Up; // 0 1 2 3
		static std::vector<Key> Keys;	// 정적 변수
		static math::Vector2 mMousePosition;

	};
}


