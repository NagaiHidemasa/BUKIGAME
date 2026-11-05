#include "DxLib.h"
#include "EnemyA.h"
#include "../../Player/Player.h"
#include "../../Camera/Camera.h"

#define ENEMY_A_HP (30)
#define ENEMY_A_DEFAULT_SPEED (1);

EnemyAData g_EnemyAData[ENEMY_A_MAX] = { 0 };
EnemyAHandle g_EnemyAHandle = { 0 };

int directionA = 1;

void InitEnemyA()
{
	EnemyAData* enemy = g_EnemyAData;
	for (int i = 0; i < ENEMY_A_MAX; i++, enemy++)
	{
		enemy->active = false;
		enemy->HP = 0;
		enemy->move.x = 0;
		enemy->move.y = 0;
	}
}

void LoadEnemyA()
{
	g_EnemyAHandle.Left = LoadGraph("Data/Enemy/EnemyA/EnemyALeft.png");
	g_EnemyAHandle.Right = LoadGraph("Data/Enemy/EnemyA/EnemyARight.png");
}

void StepEnemyA()
{
	EnemyAData* enemy = g_EnemyAData;
	PlayerData player = *GetPlayer();
	for (int i = 0; i < ENEMY_A_MAX; i++, enemy++) {
		if (!enemy->active)
		{
			return;
		}
		enemy->move.x = 0;
		enemy->move.y = 0;

		if (enemy->pos.x > player.pos.x )
		{
			enemy->move.x -= ENEMY_A_DEFAULT_SPEED;
			directionA = 1;
		}
		else if (enemy->pos.x == player.pos.x)
		{

		}
		else
		{
			enemy->move.x += ENEMY_A_DEFAULT_SPEED;
			directionA = 2;
		}

		if (enemy->pos.y > player.pos.y+20)
		{
			enemy->move.y -= ENEMY_A_DEFAULT_SPEED;
		}
		else
		{
			enemy->move.y += ENEMY_A_DEFAULT_SPEED;
		}
	}
}

void UpdateEnemyA()
{
	EnemyAData* enemy = g_EnemyAData;
	for (int i = 0; i < ENEMY_A_MAX; i++, enemy++) {
		if (!enemy->active)
		{
			return;
		}

		enemy->pos.x += enemy->move.x;
		enemy->pos.y += enemy->move.y;

		if (enemy->HP < 0)
		{
			enemy->active = false;
		}

		enemy->muteki--;
	}
}

void DrawEnemyA()
{
	EnemyAData* enemy = g_EnemyAData;
	CameraData camera = GetCamera();
	for (int i = 0; i < ENEMY_A_MAX; i++, enemy++)
	{
		if (!enemy->active)
		{
			return;
		}

		if (directionA == 1)
		{
			DrawGraph(enemy->pos.x - camera.pos.x, enemy->pos.y - camera.pos.y, g_EnemyAHandle.Left, TRUE);
		}
		else if (directionA == 2)
		{
			DrawGraph(enemy->pos.x - camera.pos.x, enemy->pos.y - camera.pos.y, g_EnemyAHandle.Right, TRUE);
		}
	}
}

void FinEnemyA()
{
	EnemyAData* enemy = g_EnemyAData;
	for (int i = 0; i < ENEMY_A_MAX; i++, enemy++)
	{
		enemy->active = false;
	}
}

EnemyAData* GetEnemyAData()
{
	return g_EnemyAData;
}

EnemyAHandle GetEnemyAHandle()
{
	return g_EnemyAHandle;
}

void EnemyHitPlayer()
{
	g_EnemyAData->muteki = 20;
}

void SpawnA()
{
	EnemyAData* enemy = g_EnemyAData;
	for (int i = 0; i < ENEMY_A_MAX; i++, enemy++)
	{
		if (!enemy->active) {
			enemy->active = true;

			enemy->HP = ENEMY_A_HP;

			enemy->pos.x = 3000;
			enemy->pos.y = 3100;

			enemy->move.x = 0.0f;
			enemy->move.y = 0.0f;

			break;
		}
	}
}
