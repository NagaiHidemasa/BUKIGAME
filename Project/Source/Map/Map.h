#pragma once
#include "MapParameter.h"

void InitdMap();
void LoaddMap();
void StartdMap();
void StepdMap();
void DrawdMap();
void FindMap();

MapData* CreatedMap(MapChipType type, VECTOR pos);
MapData* GetMap();