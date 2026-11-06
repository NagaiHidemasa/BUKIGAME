#include "DxLib.h"
#include "EnemyA/EnemyA.h"
#include "EnemyManager.h"
#include "../Player/Player.h"

void InitEnemy()
{
	InitEnemyA();
}

void LoadEnemy()
{
	LoadEnemyA();
}

void StepEnemy()
{
	StepEnemyA();
}

void UpdateEnemy()
{
	UpdateEnemyA();
}

void DrawEnemy()
{
	DrawEnemyA();
}

void FinEnemy()
{
	FinEnemyA();
}

int timer = 0;
int numx;
int numy;

void EnemySpawn()
{
	PlayerData* player = GetPlayer();

	timer++;;

	if (timer > 120) 
	{
		while (1)
		{
			numx = GetRand(1500)-700;
			if (numx > 500 || numx < -500) 
			{
				break;
			}
		}

		while (1)
		{
			numy = GetRand(900)-500;
			if (numy > 300 || numy < -300)
			{
				break;
			}
		}
		SpawnA(numx + player->pos.x, numy + player->pos.y);
		timer = 0;
	}
}
