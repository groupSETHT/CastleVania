#pragma once
#include <d3dx9.h>
#define SCREEN_WIDTH 512
#define SCREEN_HEIGHT 480
#define FRAME_RATE 60		
class Camera
{
private:
	int _WorldWidth, _WorldHeight;	//World size
	int _ViewPortX, _ViewPortY;		//Current viewport, Viewport if top-left conner of the screen


	static Camera *Instance;
public:
	static Camera *GetInstance();
	Camera(void);
	~Camera(void);


	void SetWorldSize(D3DXVECTOR2 worldSize);
	void Update(D3DXVECTOR2 characterPosition);
	void AutoUpdate();


	D3DXVECTOR2 GetViewPort() const;
	D3DXVECTOR2 GetWorldSize() const;
};

