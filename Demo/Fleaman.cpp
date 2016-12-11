#include "Fleaman.h"


Fleaman::Fleaman()
{
	idObject = IDObject::FLEAMANN;
	Init();
}

void Fleaman::Init(){
	m_pos = D3DXVECTOR2(0, 0);
	m_veloc = D3DXVECTOR2(10, 0);
	m_maxVelocity = D3DXVECTOR2(40.0f, 50.0f);
	m_action = fleaman_down;
	m_direct = 1;
	//m_lastPos = D3DXVECTOR2(0, 0);
	fleaman = CResourceManager::GetInstance()->GetResouce(FLEAMAN_ID);
	m_sprite = fleaman;
	CGameObject::SetBound();
}


void Fleaman::UpdateAnimation(CInput *m_input, float _time){
	if (m_veloc.x == 0 && m_veloc.y == 0)//normal
	{
		if (m_direct == 1){
			m_sprite->SetCurrentSprite(2);
			m_sprite->UpdateSprite();
		}
		if (m_direct == -1){
			m_sprite->SetCurrentSprite(1);
			m_sprite->UpdateSprite();
		}
	}
	if (m_veloc.x != 0 && m_veloc.y == 0){//run
		if (m_direct == 1){
			m_sprite->SetTimeAmination(0.5f);
			m_sprite->UpdateSprite(_time, 2, 3, 1);
		}
		if (m_direct == -1){

			m_sprite->SetTimeAmination(0.5f);
			m_sprite->UpdateSprite(_time, 0, 1, -1);
		}
	}
}
void Fleaman::UpdatePosition(CInput *m_input, float _time){
    //  m_veloc.x = m_maxVelocity.x;
	m_veloc.x =0.0f;
	CGameObject::UpdatePosition(m_input, _time);
}

void Fleaman::UpdateCollison(CInput *m_input, float _time)
{

}
Fleaman::~Fleaman()
{
}
