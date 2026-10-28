#include "Map.h"
#include "MapManager.h"

MapData g_Map[MAP_MAX] = { 0 };
int g_MapHandle[MAP_TYPE_MAX] = { 0 };


void InitMap()
{
	MapData* map = g_Map;
	for (int i = 0; i < MAP_MAX; i++, map++)
	{
		map->pos = VGet(0.0f, 0.0f, 0.0f);
		map->type = MAP_CHIP_NONE;
	}
}

void LoadMao()
{
	g_MapHandle[NORMAL_MAP] = LoadGraph("Data/Frore/Frore.jpg");
}


void LoadMap()
{
}

void StartMap()
{
	
}


void StepMap() 
{

}


void DrawMap() 
{
	MapData* map = g_Map;
	for (int i = 0; i < MAP_MAX; i++, map++) 
	{
		DrawGraph(0, 0, map->handle, TRUE);
	}
}


void FinMap() 
{

}

MapData* CreateMap(MapChipType type, VECTOR pos)
{
	MapData* map = g_Map;
	for (int i = 0; i < MAP_MAX; i++, map++)
	{
		map->handle = g_MapHandle[type];
		map->pos = pos;
		map->type = type;
		return map;
	}
	return nullptr;
}

MapData* GetMap()
{
	return g_Map;
}
