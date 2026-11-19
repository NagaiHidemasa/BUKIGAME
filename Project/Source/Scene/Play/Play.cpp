#include "DxLib.h"
#include "Play.h"
#include "../SceneManager.h"
#include "../../Input/Input.h"
#include "../../Map/MapManager.h"
#include "../../Player/Player.h"
#include "../../Camera/Camera.h"
#include "../../Enemy/EnemyManager.h"
#include "../../Collision/Collision.h"
#include "../../Weapon/WeaponManager.h"

//#include "../../Enemy/EnemyA/EnemyA.h"


void InitPlayScene()
{
	InitEnemy();
	InitPlayer();
	InitCamera();
	InitWeapon();
}

void LoadPlayScene()
{
	LoadEnemy();
	LoadPlayer();
	LoadMap();
	LoadWeapon();
}

void StartPlayScene()
{
	StartPlayer();
	StartMap();
	StartWeapon();
}

void StepPlayScene()
{
	StepEnemy();
	StepPlayer();
	StepCamera();
	StepWeapon();
}

void UpdatePlayScene()
{
	UpdateEnemy();
	UpdatePlayer();
	UpdateWeapon();

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
	DrawWeapon();
	DrawCamera();
}

void FinPlayScene()
{
	FinEnemy();
	FinPlayer();
	FinWeapon();
}