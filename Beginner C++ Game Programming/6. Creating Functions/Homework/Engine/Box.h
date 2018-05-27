#pragma once

#include "Graphics.h"

class Box
{
public:
	Box();
	Box(const int x, const int y);

	int GetX() const;
	int GetY() const;

	bool IsCollision(const Box& source) const;

	void MoveBy(const int x, const int y);

	void Draw(Graphics& gfx) const;

	void SetGreen(const int value);

	void SetPosition(const int x, const int y);

public:
	static constexpr int CenterBorderDistance = 5;

private:
	int x;
	int y;

	int green = 255;
};