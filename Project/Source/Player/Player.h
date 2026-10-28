#pragma once

struct PlayerData
{
	bool active;
	float moveX;
	float moveY;
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

PlayerData GetPlayer();
Handle GetHandle();