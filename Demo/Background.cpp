#include "Background.h"
Background::Background()
{

}
void Background::InitCoordinates()
{
	_CoorTile = new D3DXVECTOR3 *[w_sizey];
	for (int i = 0; i < w_sizey; ++i)
		_CoorTile[i] = new D3DXVECTOR3[w_sizex];

	Camera *cm = new Camera();
	// Lấy tọa độ mỗi tile
	for (int i = 0; i < w_sizey; i++)
	{
		for (int j = 0; j <w_sizex; j++)
		{
			D3DXVECTOR2 positionTransform = cm->Transform(i*tile_sizex, (float)j*tile_sizey);
			_CoorTile[i][j].x = positionTransform.x;
			_CoorTile[i][j].y = positionTransform.y;
			_CoorTile[i][j].z = 0;

		}
	}
}

Background::~Background()
{
}

void Background::Init(LPDIRECT3DTEXTURE9 _texture,char* _pathname){
	FILE *file;
	file = fopen(_pathname, "r");
	if (!fscanf(file, "%d", &total));
	if (!fscanf(file, "%d" "%d", &tile_sizex, &tile_sizey));
	if (!fscanf(file, "%d" "%d", &widthtile, &heighttile));
	if (!fscanf(file, "%d" "%d", &w_sizex, &w_sizey));
	map = new int*[w_sizey];
	for (int i = 0; i < w_sizey; i++)
		map[i] = new int[w_sizex];
	for (int i = 0; i < w_sizey; i++)
	{
		for (int j = 0; j <w_sizex; j++)
		{

			if (!fscanf(file, "%d", &map[i][j]))
				break;
		}
	}
	fclose(file);
	m_texture = _texture;
	
	InitCoordinates();
}
void Background::Draw(LPD3DXSPRITE _spriteHandler, D3DXVECTOR2 pos_c, int _lobeginx, int _loendx, int _lobeginy, int _loendy)
{

	RECT rect;
	int x_tile = 0;
	int y_tile = 0;
	int minRange = pos_c.x / tile_sizex;
	int maxRange = minRange + SCREEN_WIDTH / tile_sizex+4;
	//int _dy = _loendy - _lobeginy;
	int maxRangeHer = _loendy;
	int minRangeHer = maxRangeHer +1;
		int c = 0, d = 0;
		for (int i = _loendy-1; i >=_lobeginy; i--)
		{
			for (int j = minRange; j < maxRange; j++)
			{
				x_tile = (map[i][j] % (tile_sizex));
				y_tile = (map[i][j] / (tile_sizey));
				rect = { x_tile * tile_sizex, y_tile * tile_sizey, (x_tile + 1) * tile_sizex, (y_tile + 1) * tile_sizey };
				_spriteHandler->Draw(m_texture, &rect, NULL, &_CoorTile[d][c], D3DCOLOR_XRGB(255, 255, 255));
				if (d <= (SCREEN_WIDTH / tile_sizex)+2){
					d++;
				}
				else{
					d = 0;
				}
			}
			if (c < SCREEN_HEIGHT / tile_sizex ){
				c++;
			}
			else{
				c = 0;
			}
	}
}

