#pragma once
#include "DxLib.h"

enum EnemyType
{
	ENEMY_TYPE_A,
	ENEMY_CHIP_NONE,
};

#define ENEMY_A_MAX		(512)
#define ENEMY_A_WIDTH	(38)
#define ENEMY_A_HEIGHT	(30)

struct EnemyAData
{
	bool active;
	int HP;
	int muteki;
	int directionA;
	VECTOR move;
	VECTOR pos;
};

struct EnemyAHandle
{
	int Left;
	int Right;
};

struct EnemyA1Chip
{
	int enemya1;
	EnemyAData* data;
};