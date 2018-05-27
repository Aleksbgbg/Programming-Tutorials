#pragma once

#include "Graphics.h"

class Box
{
public:
	Box();
	Box(const int x, const int y);

	bool IsCollision(const Box& source) const;

	void MoveBy(const int x, const int y);

	void Draw(Graphics& gfx) const;

	void SetGreen(const int value);

private:
	int x;
	int y;

	int green = 255;
};