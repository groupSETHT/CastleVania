#include"Brick.h"
Brick::Brick(){
	idObject = IDObject::BRICKK;
	//m_pos = D3DXVECTOR2(0, 0);
	Init();
}
Brick::Brick(int _id, D3DXVECTOR2 pos){
	idObject = IDObject::BRICKK;
	m_pos = pos;
	Init();
}
void Brick::Init(){
	m_pos = D3DXVECTOR2(65, 575);
	m_veloc = D3DXVECTOR2(0, 0);
	//m_maxVelocity = D3DXVECTOR2(40.0f, 50.0f);
	//m_lastPos = D3DXVECTOR2(0, 0);
	//m_action = normal;
	spriteBrick = CResourceManager::GetInstance()->GetResouce(BRICK_ID);
	m_sprite = spriteBrick;
	CGameObject::SetBound();
}

void Brick::UpdateAnimation(CInput *_input, float _time){
	m_sprite->SetCurrentSprite(0);
	m_sprite->SetTimeAmination(0);
	m_sprite->UpdateSprite();
}

Brick::~Brick(){}

