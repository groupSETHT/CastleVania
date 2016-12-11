#ifndef RESOURCEMANAGER_H_
#define RESOURCEMANAGER_H_
#define BALL_IMAGE "Resource//Images//ball.bmp"
#define SIMON_ATTACK "Resource//Images//simon_attack_normal.png"
#define SIMON_RUN "Resource//Images//simon.png"
#define BRICK "Resource//Images//brick.png"
#define FLEAMAN "Resource//Images//Fleaman.png"




#include<d3d9.h>
#include<d3dx9.h>
#include"Sprite.h"
#include"Texture.h"

enum ResourceId {
	SIMON_RUN_ID,
	BALL_ID,
	SIMON_ATTACK_ID,
	MARIOGUN_ID,
	BRICK_ID,
	FLEAMAN_ID,
	ITEM_ID,
	BRICKBREAK_ID,	

};
 
class CResourceManager{
public:
	CSprite *simon_attack;
	CSprite *simon_run;
	CSprite *brick;
	CSprite *fleaman;

	
	
	CTexture *m_texture;
	static CResourceManager *m_resource;
	static LPDIRECT3DDEVICE9 m_pd3device;
	static HWND  m_wndHandle;
	
public:
	CResourceManager(void);
	~CResourceManager(void);

	bool Init(LPDIRECT3DDEVICE9, HWND);


	CSprite* GetResouce(ResourceId);
	
	//static

	static CResourceManager* GetInstance();
};
#endif