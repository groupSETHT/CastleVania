#include"ResourceManager.h"
CResourceManager* CResourceManager::m_resource = NULL;
LPDIRECT3DDEVICE9 CResourceManager::m_pd3device = NULL;
HWND CResourceManager::m_wndHandle = NULL;

CResourceManager::CResourceManager(void){
	simon_attack = new CSprite(6, 6, 360, 32);
	simon_run = new CSprite(8,8,280,32);
	brick = new CSprite(1, 1, 16, 16);
	fleaman = new CSprite(4, 4, 80, 17);
}
bool CResourceManager::Init(LPDIRECT3DDEVICE9 _pd3device, HWND _wndHandle){
	m_pd3device = _pd3device;
	m_wndHandle = _wndHandle;
	m_texture = new CTexture(m_pd3device);
	
	if (m_texture == NULL)
	{
		return false;
	}

	simon_attack->Init(m_texture->GetTexture(SIMON_ATTACK));
	simon_run->Init(m_texture->GetTexture(SIMON_RUN));
	brick->Init(m_texture->GetTexture(BRICK));
	fleaman->Init(m_texture->GetTexture(FLEAMAN));
	return true;
}
CSprite* CResourceManager::GetResouce(ResourceId _id){
	switch (_id)
	{
	case SIMON_ATTACK_ID :
	{
						return new CSprite(*simon_attack);
						break;
	}
	case SIMON_RUN_ID:
	{
						  return new CSprite(*simon_run);
						  break;
	}
	case BRICK_ID:
	{
					 return new CSprite(*brick);
					 break;
	}
	case FLEAMAN_ID:
	{
					 return new CSprite(*fleaman);
					 break;
	}
	default:
	{
			   return NULL;
			   break;
	}
	}

}

CResourceManager* CResourceManager::GetInstance()
{
	if (m_resource == NULL)
	{
		m_resource = new CResourceManager();
	}
	return m_resource;
}
CResourceManager::~CResourceManager(void)
{
}