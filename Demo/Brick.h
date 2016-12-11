#ifndef BRICK_H_
#define BRICK_H_
#include"Object.h"
#include"ResourceManager.h"
#include"Texture.h"


class Brick :public CGameObject
{
private:
	CSprite *spriteBrick;

public:
	Brick();
	Brick(int, D3DXVECTOR2);
	~Brick();
	void Init();
	//void Draw(LPD3DXSPRITE);

	void UpdateAnimation(CInput*, float);
};

#endif

