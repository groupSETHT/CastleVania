#pragma once
#include "Object.h"
#include"ResourceManager.h"
enum ActionFleaman
{
	fleaman_down
};
class Fleaman : public CGameObject
{
protected:
	CSprite *fleaman;
	ActionFleaman m_action;
	D3DXVECTOR2 f_Veloc;
public:
	Fleaman();
	~Fleaman();
	void Init();
	void UpdateAnimation(CInput*, float);
	void UpdateCollison(CInput*, float);
	void UpdatePosition(CInput*, float);
	void setAction(ActionFleaman action){ m_action = action; }
};

