#include"Object.h"



CGameObject::CGameObject(){
	m_pos = D3DXVECTOR2(50, 50);
	Init();
}
CGameObject::CGameObject(int _id, D3DXVECTOR2 _mpos){
	//idObject = null;
	m_pos = _mpos;
	Init();
}
CGameObject::~CGameObject(){}
void CGameObject::Init(){

	m_veloc = D3DXVECTOR2(0, 0);
	StartPostion = m_pos;
}
void CGameObject::SetBound(){
	m_bound.left = (LONG)(m_pos.x /*- m_sprite->GetSpriteWidth() / 2*/);
	m_bound.bottom = (LONG)(m_pos.y /*- m_sprite->GetSpriteHeight() / 2*/);
	m_bound.right = (LONG)(m_bound.left + m_sprite->GetSpriteWidth());
	m_bound.top = (LONG)(m_bound.bottom + m_sprite->GetSpriteHeight());


}
void CGameObject::SetBound(RECT *r){
	m_bound.left = (LONG)r->left;//(LONG)m_pos.x - m_sprite->GetSpriteWidth()/2;
	m_bound.bottom = (LONG)r->bottom;// (LONG)m_pos.y - m_sprite->GetSpriteHeight()/2;
	m_bound.right = (LONG)r->right;//(LONG)(m_bound.left + m_sprite->GetSpriteWidth());
	m_bound.top = (LONG)r->top;//(LONG)(m_bound.bottom + m_sprite->GetSpriteHeight());
}
void CGameObject::UpdatePosition(CInput *m_input, float _time){
	m_pos += m_veloc * _time;
	SetBound();
}
void CGameObject::Update(CInput *m_input, float _time){
	UpdateCollison(m_input, _time);
	UpdateAnimation(m_input, _time);
	UpdatePosition(m_input, _time);
}

void CGameObject::Draw(LPD3DXSPRITE _spriteHandler, Camera* camera){
	D3DXVECTOR2 positionTransform = camera->Transform(m_pos.x, m_pos.y);
	m_sprite->DrawSprite(_spriteHandler, positionTransform);
}
void CGameObject::UpdateAnimation(CInput *m_input, float _time)
{

}

void CGameObject::UpdateCollison(CInput *m_input, float _time)
{

}

void CGameObject::Stop()
{
	SetVelocity(D3DXVECTOR2(0, 0));
	SetMaxVelocity(D3DXVECTOR2(0, 0));
}


