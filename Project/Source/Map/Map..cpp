#include "Map.h"
#include "MapManager.h"
#include "../Camera/Camera.h"

MapData g_Map[MAP_MAX] = { 0 };
int g_MapHandle[MAP_TYPE_MAX] = { 0 };


void InitdMap()
{
	MapData* map = g_Map;
	for (int i = 0; i < MAP_MAX; i++, map++)
	{
		map->active = false;
		map->pos = VGet(0.0f, 0.0f, 0.0f);
		map->type = MAP_CHIP_NONE;
	}
}

void LoaddMap()
{
	g_MapHandle[NORMAL_MAP] = LoadGraph("Data/Frore/Frore.jpg");
}

void StartdMap()
{
	
}


void StepdMap() 
{

}


void DrawdMap() 
{
	MapData* map = g_Map;
	CameraData camera = GetCamera();

	for (int i = 0; i < MAP_MAX; i++, map++) 
	{
		if (map->active) 
		{
			DrawGraph((int) (map->pos.x-camera.pos.x), (int) (map->pos.y-camera.pos.y), map->handle, TRUE);
		}
	}
}


void FindMap() 
{

}

MapData* CreatedMap(MapChipType type, VECTOR pos)
{
	MapData* map = g_Map;
	for (int i = 0; i < MAP_MAX; i++, map++)
	{
		if (!map->active)
		{
			map->active = true;
			map->handle = g_MapHandle[type];
			map->pos = pos;
			map->type = type;
			return map;
		}
	}
	return nullptr;
}

MapData* GetMap()
{
	return g_Map;
}
