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
void Camera::SetViewPort(D3DXVECTOR2 viewPort){
	_ViewPortX = viewPort.x;
	_ViewPortY = viewPort.y;
}
void Camera::Update(D3DXVECTOR2 characterPosition)
{
	if (characterPosition.x - SCREEN_WIDTH / 2 < 0)
	{
		_ViewPortX = 0;
	}
	else 
	{
			_ViewPortX = (LONG(characterPosition.x) - SCREEN_WIDTH/2) ;
	}

	if (characterPosition.y - SCREEN_HEIGHT / 2 < 0)
	{
		_ViewPortY = SCREEN_HEIGHT;
	}
	else
	{
		if (characterPosition.y + SCREEN_WIDTH / 2 < _WorldWidth)
		{
			_ViewPortY = _WorldHeight;
		}
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

D3DXVECTOR2 Camera::GetViewPort() 
{
	return D3DXVECTOR2(float(_ViewPortX), float(_ViewPortY));
}

D3DXVECTOR2 Camera::GetWorldSize() 
{
	return D3DXVECTOR2(float(_WorldWidth), float(_WorldHeight));
}
D3DXVECTOR2 Camera::Transform(int x, int y)
{
	D3DXMATRIX matrix;
	D3DXMatrixIdentity(&matrix);
	matrix._22 = -1;
	matrix._41 = -_ViewPortX;
	matrix._42 = _ViewPortY;

	D3DXVECTOR3 pos3(x, y, 1);
	D3DXVECTOR4 MatrixResult;
	D3DXVec3Transform(&MatrixResult, &pos3, &matrix);

	D3DXVECTOR2 result = D3DXVECTOR2(MatrixResult.x, MatrixResult.y);
	return result;
}