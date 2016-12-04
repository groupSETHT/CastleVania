#include "Camera.h"

Camera *Camera::Instance = NULL;

Camera::Camera(void)
{
	_ViewPortX = 0;
	_ViewPortY = SCREEN_HEIGHT;
}

Camera::~Camera(void)
{
}

Camera *Camera::GetInstance()
{
	if (Instance == NULL)
	{
		Instance = new Camera();
	}
	return Instance;
}

void Camera::SetWorldSize(D3DXVECTOR2 worldSize)
{
	_WorldWidth = worldSize.x;
	_WorldHeight = worldSize.y;
}

void Camera::Update(D3DXVECTOR2 characterPosition)
{
	//Update X axis
	//If character in begin of the world
	if (characterPosition.x - SCREEN_WIDTH / 2 < 0)
	{
		_ViewPortX = 0;
	}
	else
	{
		////If character in end of world
		//if (characterPosition.x + SCREEN_WIDTH / 2 > _WorldWidth)
		//{
		//	_ViewPortX = _WorldWidth - SCREEN_WIDTH;
		//}
		////Normal case
		//else
		//{
			_ViewPortX = LONG(characterPosition.x) - SCREEN_WIDTH / 2;
		//}
	}

	//Update Y axis
	//If character in begin of the world
	if (characterPosition.y - SCREEN_HEIGHT / 2 < 0)
	{
		_ViewPortY = SCREEN_HEIGHT;
	}
	else
	{
		//If character in end of world
		if (characterPosition.y + SCREEN_WIDTH / 2 < _WorldWidth)
		{
			_ViewPortY = _WorldHeight;
		}
		//Normal case
		else
		{
			_ViewPortY = characterPosition.y + SCREEN_WIDTH / 2;
		}
	}
}

void Camera::AutoUpdate()
{
	if (_ViewPortX < _WorldWidth - SCREEN_WIDTH)
		_ViewPortX += 3;
}

D3DXVECTOR2 Camera::GetViewPort() const
{
	return D3DXVECTOR2(float(_ViewPortX), float(_ViewPortY));
}

D3DXVECTOR2 Camera::GetWorldSize() const
{
	return D3DXVECTOR2(float(_WorldWidth), float(_WorldHeight));
}