#pragma once

#include "Graphics.h"

class SpriteCodex
{
public:
	static void DrawDude(Graphics& gfx, const int x, const int y);

	static void DrawPoo(Graphics& gfx, const int x, const int y);

	static void DrawGameOver(Graphics& gfx, const int x, const int y);
};