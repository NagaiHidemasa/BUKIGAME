#pragma once

struct PlayerData
{
	bool active;
	int Level;
	int HP;
	int experience;
	float ATK;
	VECTOR move;
	VECTOR pos;
};

struct Handle
{
	int nomal;
	int left;
	int right;
	int bac;
};

void InitPlayer();
void LoadPlayer();
void StartPlayer();
void StepPlayer();
void UpdatePlayer();
void DrawPlayer();
void FinPlayer();

PlayerData* GetPlayer();
Handle GetHandle();

void PlayerHitEnemy();