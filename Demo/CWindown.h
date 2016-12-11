

#ifndef CWINDOWN_H_
#define CWINDOWN_H_
#include <d3d9.h>
#include <d3dx9.h>
#include <Windows.h>

#define NameClass "Castle Vania"
#define SCREEN_WIDTH   208
#define SCREEN_HEIGHT 208
class CWindown
{
private:
	HINSTANCE hInstance;
	HWND hWnd;


public:
	CWindown(void);
	CWindown(HINSTANCE);
	bool initWindows();
	HINSTANCE gethInstance();
	HWND getHandle();

	static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
	~CWindown(void);
};
#endif