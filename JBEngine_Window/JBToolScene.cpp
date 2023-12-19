#include "JBToolScene.h"
#include "JBObject.h"
#include "JBTile.h"
#include "JBTilemapRenderer.h"
#include "JBResources.h"
#include "JBTexture.h"
#include "JBCamera.h"
#include "JBRenderer.h"
#include "JBInput.h"

namespace JB
{
	ToolScene::ToolScene()
	{
	}
	ToolScene::~ToolScene()
	{
	}
	void ToolScene::Initialize()
	{
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None, Vector2(640.0f, 360.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;

		Tile* tile = object::Instantiate<Tile>(eLayerType::Tile);
		TilemapRenderer* tmr = tile->AddComponent<TilemapRenderer>();

		tmr->SetTexture(Resources::Find<graphics::Texture>(L"SpringFloor"));

		Scene::Initialize();
	}
	void ToolScene::Update()
	{
		Scene::Update();
	}
	void ToolScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::LButton))
		{
			Vector2 pos = Input::GetMousePosition();

			int idxX = pos.x / TilemapRenderer::TileSize.x;
			int idxY = pos.y / TilemapRenderer::TileSize.y;

			Tile* tile = object::Instantiate<Tile>(eLayerType::Tile);
			TilemapRenderer* tmr = tile->AddComponent<TilemapRenderer>();
			tmr->SetTexture(Resources::Find<graphics::Texture>(L"SpringFloor"));
			tmr->SetIndex(TilemapRenderer::SelectedIndex);

			tile->SetPosition(idxX, idxY);
		}
		
	}
	void ToolScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		for (size_t i = 0; i < 50; i++)
		{
			MoveToEx(hdc, TilemapRenderer::TileSize.x * i, 0, NULL);
			LineTo(hdc, TilemapRenderer::TileSize.x * i, 1000);
		}

		for (size_t i = 0; i < 50; i++)
		{
			MoveToEx(hdc, 0, TilemapRenderer::TileSize.y * i, NULL);
			LineTo(hdc, 1300, TilemapRenderer::TileSize.y * i);
		}
	}
	void ToolScene::OnEnter()
	{
		Scene::OnEnter();
	}
	void ToolScene::OnExit()
	{
		Scene::OnExit();
	}
}

LRESULT CALLBACK WndTileProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_LBUTTONDOWN:
	{
		POINT mousePos = {};
		GetCursorPos(&mousePos);
		ScreenToClient(hWnd, &mousePos);

		JB::math::Vector2 mousePosition;
		mousePosition.x = mousePos.x;
		mousePosition.y = mousePos.y;

		int idxX = mousePosition.x / JB::TilemapRenderer::OriginTileSize.x;
		int idxY = mousePosition.y / JB::TilemapRenderer::OriginTileSize.y;

		JB::TilemapRenderer::SelectedIndex = Vector2(idxX, idxY);
	}
	break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);

		JB::graphics::Texture* texture = JB::Resources::Find<JB::graphics::Texture>(L"SpringFloor");

		TransparentBlt(hdc
			, 0, 0
			, texture->GetWidth()
			, texture->GetHeight()
			, texture->GetHdc()
			, 0, 0
			, texture->GetWidth()
			, texture->GetHeight()
			, RGB(255, 0, 255));

		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}