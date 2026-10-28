#pragma once
#include "MapParameter.h"

void InitMap();
void LoadMao();
void StartMap();
void StepMap();
void DrawMap();
void FinMap();

MapData* CreateMap(MapChipType type, VECTOR pos);
MapData* GetMap();