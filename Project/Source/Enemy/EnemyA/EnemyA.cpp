#include "DxLib.h"
#include "EnemyA.h"
#include "../../Player/Player.h"
#include "../../Camera/Camera.h"
#include <math.h>

#define ENEMY_A_HP (30)
#define ENEMY_A_DEFAULT_SPEED (1);

EnemyAData g_EnemyAData[ENEMY_A_MAX] = { 0 };
EnemyAHandle g_EnemyAHandle = { 0 };


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

	for (int i = 0; i < ENEMY_A_MAX; i++, enemy++)
	{
		if (!enemy->active)
		{
			continue;
		}

		EnemyAData* hitEnemy = nullptr;
		EnemyAData* enemya = g_EnemyAData;
		for (int p = 0; p < ENEMY_A_MAX; p++, enemya++)
		{
			if (enemy != enemya &&
				enemy->pos.x - enemya->pos.x < 24 && enemy->pos.x - enemya->pos.x > -24 &&
				enemy->pos.y - enemya->pos.y< 36 && enemy->pos.y - enemya->pos.y > -36)
			{
				hitEnemy = enemya;
				break;
			}
		}

		if (hitEnemy != nullptr)
		{
			bool isHitEnemyRight = (enemy->pos.x - hitEnemy->pos.x) < 0;
			float moveX = (24 - fabs(enemy->pos.x - hitEnemy->pos.x)) / 2;
			if (isHitEnemyRight)
			{
				enemy->pos.x -= moveX;
				hitEnemy->pos.x += moveX;
			}
			else
			{
				enemy->pos.x += moveX;
				hitEnemy->pos.x -= moveX;
			}

			bool isHitEnemyUp = (enemy->pos.y - hitEnemy->pos.y) < 0;
			float moveY = (36 - fabs(enemy->pos.y - hitEnemy->pos.y)) / 2;
			if (isHitEnemyUp)
			{
				enemy->pos.y -= moveY;
				hitEnemy->pos.y += moveY;
			}
			else
			{
				enemy->pos.y += moveY;
				hitEnemy->pos.y -= moveY;
			}
		}
	}

	enemy = g_EnemyAData;
	for (int i = 0; i < ENEMY_A_MAX; i++, enemy++)
	{
		if (!enemy->active)
		{
			continue;
		}
		enemy->move.x = 0;
		enemy->move.y = 0;

		if (enemy->pos.x > player.pos.x)
		{
			enemy->move.x -= ENEMY_A_DEFAULT_SPEED;
			enemy->directionA = 1;
		}
		else if (enemy->pos.x == player.pos.x)
		{

		}
		else
		{
			enemy->move.x += ENEMY_A_DEFAULT_SPEED;
			enemy->directionA = 2;
		}

		if (enemy->pos.y > player.pos.y )
		{
			enemy->move.y -= ENEMY_A_DEFAULT_SPEED;
		}
		else
		{
			enemy->move.y += ENEMY_A_DEFAULT_SPEED;
		}
	}




	/*
	EnemyAData* enemy = g_EnemyAData;
	PlayerData player = *GetPlayer();
	for (int i = 0; i < ENEMY_A_MAX; i++, enemy++)
	{
		if (!enemy->active)
		{
			return;
		}
		enemy->move.x = 0;
		enemy->move.y = 0;


		EnemyAData* hitEnemy = nullptr;
		EnemyAData* enemya = g_EnemyAData;
		for (int p = 0; p < ENEMY_A_MAX; p++, enemya++)
		{
			if (enemy != enemya &&
				enemy->pos.x - enemya->pos.x < 10 && enemy->pos.x - enemya->pos.x > -10 &&
				enemy->pos.y - enemya->pos.y< 20 && enemy->pos.y - enemya->pos.y > -20)
			{
				hitEnemy = enemya;
				break;
			}
		}

		if (hitEnemy == nullptr)
		{
			if (enemy->pos.x > player.pos.x)
			{
				enemy->move.x -= ENEMY_A_DEFAULT_SPEED;
				enemy->directionA = 1;
			}
			else if (enemy->pos.x == player.pos.x)
			{

			}
			else
			{
				enemy->move.x += ENEMY_A_DEFAULT_SPEED;
				enemy->directionA = 2;
			}

			if (enemy->pos.y > player.pos.y + 20)
			{
				enemy->move.y -= ENEMY_A_DEFAULT_SPEED;
			}
			else
			{
				enemy->move.y += ENEMY_A_DEFAULT_SPEED;
			}
		}
		else
		{
			bool isHitEnemyRight = (enemy->pos.x - hitEnemy->pos.x) < 0;
			float moveX = (10 - fabs(enemy->pos.x - hitEnemy->pos.x)) / 2;
			if (isHitEnemyRight)
			{
				enemy->pos.x -= moveX;
				hitEnemy->pos.x += moveX;
			}
			else
			{
				enemy->pos.x += moveX;
				hitEnemy->pos.x -= moveX;
			}


			bool isHitEnemyUp = (enemy->pos.y - hitEnemy->pos.y) < 0;
			float moveY = (10 - fabs(enemy->pos.y - hitEnemy->pos.y)) / 2;
			if (isHitEnemyUp)
			{
				enemy->pos.y -= moveY;
				hitEnemy->pos.y += moveY;
			}
			else
			{
				enemy->pos.y += moveY;
				hitEnemy->pos.y -= moveY;
			}

		}
	}
	*/
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

		if (enemy->directionA == 1)
		{
			DrawGraph(enemy->pos.x - camera.pos.x, enemy->pos.y - camera.pos.y, g_EnemyAHandle.Left, TRUE);
		}
		else if (enemy->directionA == 2)
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

void EnemyAHitEnemyA()
{

}


void SpawnA(float x, float y)
{
	EnemyAData* enemy = g_EnemyAData;
	for (int i = 0; i < ENEMY_A_MAX; i++, enemy++)
	{
		if (!enemy->active) {
			enemy->active = true;

			enemy->HP = ENEMY_A_HP;

			enemy->pos.x = x;
			enemy->pos.y = y;

			enemy->move.x = 0.0f;
			enemy->move.y = 0.0f;

			break;
		}
	}
}
