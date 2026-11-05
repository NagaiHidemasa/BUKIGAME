#include "DxLib.h"
#include "Collision.h"
#include <math.h>

#include "../Player/Player.h"
#include "../Enemy//EnemyA/EnemyA.h"

#define PLAYER_SIZE_X (58)
#define PLAYER_SIZE_Y (50)

bool CheckSquareSquare(float squareA_PosX, float squareA_PosY, float squareA_Width, float squareA_Height, float squareB_PosX, float squareB_PosY, float squareB_Width, float squareB_Height)
{
	float leftA = squareA_PosX;
	float rightA = squareA_PosX + squareA_Width;
	float topA = squareA_PosY;
	float bottomA = squareA_PosY + squareA_Height;

	float leftB = squareB_PosX;
	float rightB = squareB_PosX + squareB_Width;
	float topB = squareB_PosY;
	float bottomB = squareB_PosY + squareB_Height;

	if (rightA >= leftB && leftA <= rightB)
	{
		if (bottomA >= topB && topA <= bottomB)
		{
			return true;
		}
	}
	return false;
}

void ChecCollision()
{
	ChecA_Player();
}

void ChecA_Player() 
{	
	PlayerData* player = GetPlayer();
	EnemyAData* enemy = GetEnemyAData();

	for (int i = 0; i < ENEMY_A_MAX; i++, enemy++)
	{
		if (enemy->muteki < 0) {
			if (CheckSquareSquare(player->pos.x, player->pos.y, PLAYER_SIZE_Y, PLAYER_SIZE_X,
				enemy->pos.x, enemy->pos.y, 38, 30))
			{
				PlayerHitEnemy();
				EnemyHitPlayer();
			}
		}
	}
}