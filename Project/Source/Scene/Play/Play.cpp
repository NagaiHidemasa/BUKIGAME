#include "DxLib.h"
#include "Play.h"
#include "../SceneManager.h"
#include "../../Input/Input.h"
#include "../../Map/MapManager.h"
#include "../../Player/Player.h"


void InitPlayScene()
{
	InitPlayer();
}

void LoadPlayScene()
{
	LoadPlayer();
	LoadMap();
}

void StartPlayScene()
{
	StartPlayer();
	StartMap();
}

void StepPlayScene()
{
	StepPlayer();
}

void UpdatePlayScene()
{
	UpdatePlayer();
}

void DrawPlayScene() 
{
	DrawMap();
	DrawPlayer();
}

void FinPlayScene()
{
	FinPlayer();
}