#pragma once
#include "JBEntity.h"


// 게임에서 사용되는 데이터
// 이미지, 사운드, 게임 플레이 데이터 
namespace JB
{
	class Resource : public Entity
	{
	public:
		Resource(enums::eResourceType type);
		virtual ~Resource();

		virtual HRESULT Load(const std::wstring& path) = 0;

		const std::wstring& GetPath() { return mPath; }
		void SetPath(const std::wstring& path) { mPath = path; }

	private:
		const enums::eResourceType mType;
		std::wstring mPath;
	};
}


