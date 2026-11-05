#pragma once
#include "DxLib.h"

enum EnemyType
{
	ENEMY_TYPE_A,
};

#define ENEMY_A_MAX		(512)
#define ENEMY_A_WIDTH	(88)
#define ENEMY_A_HEIGHT	(70)

struct EnemyAData
{
	bool active;
	int HP;
	int muteki;
	VECTOR move;
	VECTOR pos;
};

struct EnemyAHandle
{
	int Left;
	int Right;
};