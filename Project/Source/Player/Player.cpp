#include "DxLib.h"
#include "Player.h"
#include "../Input/Input.h"

#define PLAYER_DEFAULT_POS_X (400)
#define PLAYER_DEFAULT_POS_Y (500)
#define PLAYER_MOVE_SPEED (4.0f)

PlayerData g_PlayerData = { 0 };
Handle g_handle = { 0 };

int BUKIChangeTiime = 0;
int direction = 1;

void InitPlayer()
{
	g_PlayerData.pos.x = PLAYER_DEFAULT_POS_X;
	g_PlayerData.pos.y = PLAYER_DEFAULT_POS_Y;
	g_PlayerData.moveX = 0.0f;
	g_PlayerData.moveY = 0.0f;
	g_PlayerData.active = false;
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
}

void StepPlayer()
{
	if (!g_PlayerData.active) 
	{
		return;
	}
	g_PlayerData = g_PlayerData;

	g_PlayerData.moveX = 0;
	g_PlayerData.moveY = 0;

	if (IsInputKey(KEY_UP))
	{
		g_PlayerData.moveY -= PLAYER_MOVE_SPEED;
		direction = 1;
	}

	else if(IsInputKey(KEY_DOWN))
	{
		g_PlayerData.moveY += PLAYER_MOVE_SPEED;
		direction = 2;
	}

	if (IsInputKey(KEY_LEFT))
	{
		g_PlayerData.moveX -= PLAYER_MOVE_SPEED;
		direction = 3;
	}

	else if (IsInputKey(KEY_RIGHT))
	{
		g_PlayerData.moveX += PLAYER_MOVE_SPEED;;
		direction = 4;
	}

	if (IsInputKey(KEY_A))
	{
		if (BUKIChangeTiime >= 30) 
		{

		}
	}
}

void UpdatePlayer()
{
	BUKIChangeTiime++;

	if (!g_PlayerData.active) return;

	g_PlayerData.pos.x += g_PlayerData.moveX;
	g_PlayerData.pos.y += g_PlayerData.moveY;

	DrawFormatString(0, 0, GetColor(255, 255, 255), "X%d Y%d",g_PlayerData.pos.x, g_PlayerData.pos.y);


}

void DrawPlayer()
{
	if (!g_PlayerData.active) return;

	if (direction == 1) 
	{
		DrawGraphF(g_PlayerData.pos.x,g_PlayerData.pos.y,g_handle.bac, TRUE);
	}
	
	if (direction == 2)
	{
		DrawGraphF(g_PlayerData.pos.x, g_PlayerData.pos.y, g_handle.nomal, TRUE);
	}

	if (direction == 3)
	{
		DrawGraphF(g_PlayerData.pos.x, g_PlayerData.pos.y, g_handle.left, TRUE);
	}

	if (direction == 4)
	{
		DrawGraphF(g_PlayerData.pos.x, g_PlayerData.pos.y, g_handle.right, TRUE);
	}
}

void FinPlayer()
{
}

PlayerData GetPlayer()
{
	return g_PlayerData;
}

Handle GetHandle()
{
	return g_handle;
}