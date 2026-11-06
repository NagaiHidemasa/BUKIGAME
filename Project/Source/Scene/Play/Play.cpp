#include "DxLib.h"
#include "Play.h"
#include "../SceneManager.h"
#include "../../Input/Input.h"
#include "../../Map/MapManager.h"
#include "../../Player/Player.h"
#include "../../Camera/Camera.h"
#include "../../Enemy/EnemyManager.h"
#include "../../Collision/Collision.h"

//#include "../../Enemy/EnemyA/EnemyA.h"


void InitPlayScene()
{
	InitEnemy();
	InitPlayer();
	InitCamera();
}

void LoadPlayScene()
{
	LoadEnemy();
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
	StepEnemy();
	StepPlayer();
	StepCamera();
}

void UpdatePlayScene()
{
	UpdateEnemy();
	UpdatePlayer();
	

	//

	EnemySpawn();

	//

	ChecCollision();
}

void DrawPlayScene() 
{
	DrawMap();
	DrawEnemy();
	DrawPlayer();
	DrawCamera();
}

void FinPlayScene()
{
	FinEnemy();
	FinPlayer();
}