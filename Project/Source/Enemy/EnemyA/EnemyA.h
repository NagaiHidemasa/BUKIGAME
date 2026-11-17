#pragma once
#include "../EnemyParameter.h"

void InitEnemyA();
void LoadEnemyA();
void StepEnemyA();
void UpdateEnemyA();
void DrawEnemyA();
void FinEnemyA();

EnemyAData* GetEnemyAData();
EnemyAHandle GetEnemyAHandle();

void EnemyAHitEnemyA();
void EnemyHitPlayer();

void SpawnA(float x,float y);