#include "DxLib.h"
#include "Player.h"

#define PLAYER_DEFAULT_POS_X (10000-9500)
#define PLAYER_DEFAULT_POS_Y (7500-7400)

PlayerData g_PlayerData = { 0 };
Handle g_handle = { 0 };

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
}

void UpdatePlayer()
{
}

void DrawPlayer()
{
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
