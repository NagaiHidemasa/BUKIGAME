#include "DxLib.h"
#include "Ono.h"
#include "../WeaponParamater.h"
#include "../../Player/Player.h"

OnoData g_OnoData = { 0 };
OnoHandle g_OnoHandle = { 0 };

void InitOno()
{
	g_OnoData.totu = 0;
	g_OnoData.count = 0;
	g_OnoData.atac = 0;
	g_OnoData.atac = false;
}

void LoadOno()
{
	g_OnoHandle.Vr1R = LoadGraph("Data/Buki/Ono/OnoRight.png");
	g_OnoHandle.Vr1L = LoadGraph("Data/Buki/Ono/OnoLeft.png");
}

void StartOno()
{

}

void StepOno()
{
	PlayerData* player = GetPlayer();
	if (player->direction == 2) 
	{
		g_OnoData.Onodirection = true;
	}

	if (player->direction == 3)
	{
		g_OnoData.Onodirection = false;
	}
}

void UpdateOno()
{

	g_OnoData.count++;

	if (g_OnoData.count >= 60)
	{
		g_OnoData.atac = true;
	}
		
	if (g_OnoData.atac = true) 
	{

		//UŒ‚‚·‚éŠÖ”‚ðì‚é
		g_OnoData.atac = false;
	}
}

void DrawOno()
{
	PlayerData* player = GetPlayer();
	if (g_OnoData.totu == 1) {
		if (g_OnoData.Onodirection = true)
		{
			DrawGraph(player->pos.x - 35, player->pos.y - 10, g_OnoHandle.Vr1L, TRUE);
		}
		if (g_OnoData.Onodirection == false) 
		{
			DrawGraph(player->pos.x + 65, player->pos.y - 10, g_OnoHandle.Vr1R, TRUE);
		}
	}
	/*2“ÊˆÈ~‚à‚Å‚«‚½‚ç–Y‚ê‚¸
		if (g_OnoData.totu == 2) {
		if (g_OnoData.Onodirection = true)
		{
			DrawGraph(player->pos.x - 35, player->pos.y - 10, g_OnoHandle.Vr2L, TRUE);
		}
		if (g_OnoData.Onodirection == false) 
		{
			DrawGraph(player->pos.x + 65, player->pos.y - 10, g_OnoHandle.Vr2R, TRUE);
		}
	}
	*/
	
}

void FinOno()
{
}