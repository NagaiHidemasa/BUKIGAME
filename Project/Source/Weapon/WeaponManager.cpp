#include "WeaponManager.h"
#include "WeaponOno/Ono.h"
#include "../Player/Player.h"

void InitWeapon()
{
	InitOno();

}

void LoadWeapon()
{
	LoadOno();

}

void StartWeapon()
{
	StartOno();

}

void StepWeapon()
{
	PlayerData* player = GetPlayer();
	if (player->have == 1) 
	{
		StepOno();
	}

}

void UpdateWeapon()
{
	PlayerData* player = GetPlayer();
	if (player->have == 1)
	{
		UpdateOno();
	}
}

void DrawWeapon()
{
	PlayerData* player = GetPlayer();
	if (player->have == 1)
	{
		DrawOno();
	}
}

void FinWeapon()
{
	FinOno();
}
