#include "DxLib.h"
#include "Player.h"
#include "../Input/Input.h"
#include "../Camera/Camera.h"

#define PLAYER_DEFAULT_POS_X (3000)
#define PLAYER_DEFAULT_POS_Y (3000)
#define PLAYER_MOVE_SPEED (2.0f)
#define DIRECTION_UP (0)
#define DIRECTION_DOWN (1)
#define DIRECTION_LEFT (2)
#define DIRECTION_RIGHT (3)

PlayerData g_PlayerData = { 0 };
Handle g_handle = { 0 };

int BUKIChangeTiime = 0;

void InitPlayer()
{
	g_PlayerData.pos.x = PLAYER_DEFAULT_POS_X;
	g_PlayerData.pos.y = PLAYER_DEFAULT_POS_Y;
	g_PlayerData.Level = 0;
	g_PlayerData.experience = 0;
	g_PlayerData.HP = 0;
	g_PlayerData.active = false;
	g_PlayerData.have = 0;
	g_PlayerData.bac = 0;
}

void LoadPlayer()
{
	g_handle.nomal = LoadGraph("Data/Player/Player.png");
	g_handle.left= LoadGraph("Data/Player/PlayerLeft.png");
	g_handle.right = LoadGraph("Data/Player/PlayerRight.png");
	g_handle.bac= LoadGraph("Data/Player/PlayerBac.png");
}

void StartPlayer()
{
	g_PlayerData.active = true;
	g_PlayerData.HP = 100;
}

void StepPlayer()
{
	if (!g_PlayerData.active) 
	{
		return;
	}
	g_PlayerData = g_PlayerData;

	g_PlayerData.move.x = 0;
	g_PlayerData.move.y = 0;

	if (IsInputKey(KEY_UP))
	{
		g_PlayerData.move.y-= PLAYER_MOVE_SPEED;
		g_PlayerData.direction= DIRECTION_UP;
	}

	else if(IsInputKey(KEY_DOWN))
	{
		g_PlayerData.move.y+= PLAYER_MOVE_SPEED;
		g_PlayerData.direction = DIRECTION_DOWN;
	}

	if (IsInputKey(KEY_LEFT))
	{
		g_PlayerData.move.x-= PLAYER_MOVE_SPEED;
		g_PlayerData.direction = DIRECTION_LEFT;
	}

	else if (IsInputKey(KEY_RIGHT))
	{
		g_PlayerData.move.x += PLAYER_MOVE_SPEED;;
		g_PlayerData.direction = DIRECTION_RIGHT;
	}

	if (IsInputKey(KEY_A))
	{
		if (BUKIChangeTiime >= 30) 
		{
			//武器チェンジ予定
		}
	}
}

void UpdatePlayer()
{
	BUKIChangeTiime++;

	if (g_PlayerData.HP < 0)
	{
		g_PlayerData.active = false;
	}

	if (!g_PlayerData.active) return;

	g_PlayerData.pos.x += g_PlayerData.move.x;
	g_PlayerData.pos.y += g_PlayerData.move.y;
}

void DrawPlayer()
{
	if (!g_PlayerData.active) return;

	CameraData camera = GetCamera();

	if (g_PlayerData.direction == 0)
	{
		DrawGraphF(g_PlayerData.pos.x-camera.pos.x,g_PlayerData.pos.y-camera.pos.y,g_handle.bac, TRUE);
	}
	
	if (g_PlayerData.direction == 1)
	{
		DrawGraphF(g_PlayerData.pos.x - camera.pos.x, g_PlayerData.pos.y - camera.pos.y, g_handle.nomal, TRUE);
	}

	if (g_PlayerData.direction == 2)
	{
		DrawGraphF(g_PlayerData.pos.x - camera.pos.x, g_PlayerData.pos.y - camera.pos.y, g_handle.left, TRUE);
	}

	if (g_PlayerData.direction == 3)
	{
		DrawGraphF(g_PlayerData.pos.x - camera.pos.x, g_PlayerData.pos.y - camera.pos.y, g_handle.right, TRUE);
	}
	DrawFormatString(0, 0, GetColor(255, 255, 255), "レベル %d",g_PlayerData.Level);
	DrawFormatString(0, 100, GetColor(255, 255, 255), "HP %d", g_PlayerData.HP);

}

void FinPlayer()
{
}

PlayerData *GetPlayer()
{
	return &g_PlayerData;
}

Handle GetHandle()
{
	return g_handle;
}

void PlayerHitEnemy()
{
	g_PlayerData.HP--;
}
