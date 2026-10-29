#pragma once

enum Inputkey
{
	KEY_UP		= (1<<0),
	KEY_DOWN	= (1<<1),
	KEY_LEFT	= (1<<2),
	KEY_RIGHT	= (1<<3),
	KEY_Z		= (1<<4),
	KEY_A		= (1<<5),
};

void InitInput();
void UpdateInput();
void DrawInput();
void FinInput();

bool IsInputKey(Inputkey key);
bool IsTriggerKey(Inputkey key);