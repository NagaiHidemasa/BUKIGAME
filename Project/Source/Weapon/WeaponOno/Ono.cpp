#include "DxLib.h"
#include "Ono.h"
#include "../WeaponParamater.h"
#include "../../Player/Player.h"
#include "../../Camera/Camera.h"
#include "../../Collision/Collision.h"
#include "../../Enemy/EnemyA/EnemyA.h"

OnoData g_OnoData = { 0 };
OnoHandle g_OnoHandle = { 0 };

void InitOno()
{
	g_OnoData.totu = 0;
	g_OnoData.count = 0;
	g_OnoData.atac = 0;
	g_OnoData.atact = false;
	g_OnoData.Onodirection = true;
}

void LoadOno()
{
	g_OnoHandle.Vr1R = LoadGraph("Data/Buki/Ono/OnoRight.png");
	g_OnoHandle.Vr1L = LoadGraph("Data/Buki/Ono/OnoLeft.png");
}

void StartOno()
{
	g_OnoData.oatacH = 30;
	g_OnoData.oatacW = 20;
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
	PlayerData* player = GetPlayer();
	g_OnoData.count++;

	if (g_OnoData.count >= 70)
	{
		g_OnoData.atac = true;
		g_OnoData.count = 0;

		atacOno(player->pos, g_OnoData.oatacW, g_OnoData.oatacH);
	}

	if (g_OnoData.atac = true)
	{
		g_OnoData.atact++;

		if (g_OnoData.atact >= 10)
		{
			g_OnoData.atac = false;
		}
	}
}

void DrawOno()
{
	PlayerData* player = GetPlayer();
	CameraData camera = GetCamera();
	if (g_OnoData.totu == 0) {
		if (g_OnoData.Onodirection == true)
		{
			DrawGraph(player->pos.x - 30 - camera.pos.x, player->pos.y - 10 - camera.pos.y, g_OnoHandle.Vr1L, TRUE);
		}
		if (g_OnoData.Onodirection == false)
		{
			DrawGraph(player->pos.x + 50 - camera.pos.x, player->pos.y - 10 - camera.pos.y, g_OnoHandle.Vr1R, TRUE);
		}
	}
	/*2“ÊˆÈ~‚à‚Å‚«‚½‚ç–Y‚ê‚¸
		if (g_OnoData.totu == 1) {
		if (g_OnoData.Onodirection == true)
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

void atacOno(VECTOR poso, int w, int h)
{
	EnemyAData* enemy = GetEnemyAData();
	PlayerData* player = GetPlayer();
	CameraData camera = GetCamera();

	for (int i = 0; i < ENEMY_A_MAX; i++, enemy++)
	{
		if (!enemy->active)
		{
			continue;
		}


	if(CheckSquareSquare(poso.x, poso.y, w, h,
			enemy->pos.x, enemy->pos.y, ENEMY_A_WIDTH, ENEMY_A_HEIGHT))
		{
			float num = g_OnoData.atac * player->ATK;
			enemy->HP -= g_OnoData.atac * player->ATK;
			DrawFormatString(enemy->pos.x - camera.pos.x, enemy->pos.y - camera.pos.y - 20, GetColor(255, 255, 255), "%d", num);
		}
	}
}