#pragma once
#include "DxLib.h"

#define MAP_MAX 1350
#define MAP_CHIP_X_NUM (45)
#define MAP_CHIP_Y_NUM (30)
#define MAP_CHIP_WIDTH (1254.0f)
#define MAP_CHIP_HEIGHT (1254.0f)

enum MapChipType
{
	MAP_CHIP_NONE,
	NORMAL_MAP,
	MAP_TYPE_MAX,
};

struct MapData
{
	int handle;
	MapChipType type;
	VECTOR pos;
};

struct MapChipData
{
	int mapChip;
	MapData* data;
};