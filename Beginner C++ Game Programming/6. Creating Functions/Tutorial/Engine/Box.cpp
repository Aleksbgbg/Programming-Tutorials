#include "Box.h"

Box::Box()
	:
	Box{ 0, 0 }
{
}

Box::Box(const int x, const int y)
	:
	x{ x },
	y{ y }
{
}

bool Box::IsCollision(const Box& source) const
{
	return (source.x - 5) <= (x + 5) && (x - 5) <= (source.x + 5) &&
		   (source.y - 5) <= (y + 5) && (y - 5) <= (source.y + 5);
}

void Box::MoveBy(const int x, const int y)
{
	this->x += x;
	this->y += y;
}

void Box::Draw(Graphics& gfx) const
{
	// Horizontal line (top)
	gfx.PutPixel(x - 5, y + 5, 255, green, 255);
	gfx.PutPixel(x - 4, y + 5, 255, green, 255);
	gfx.PutPixel(x - 3, y + 5, 255, green, 255);
	gfx.PutPixel(x + 3, y + 5, 255, green, 255);
	gfx.PutPixel(x + 4, y + 5, 255, green, 255);
	gfx.PutPixel(x + 5, y + 5, 255, green, 255);

	// Horizontal line (bottom)
	gfx.PutPixel(x - 5, y - 5, 255, green, 255);
	gfx.PutPixel(x - 4, y - 5, 255, green, 255);
	gfx.PutPixel(x - 3, y - 5, 255, green, 255);
	gfx.PutPixel(x + 3, y - 5, 255, green, 255);
	gfx.PutPixel(x + 4, y - 5, 255, green, 255);
	gfx.PutPixel(x + 5, y - 5, 255, green, 255);

	// Vertical line (left)
	gfx.PutPixel(x - 5, y - 5, 255, green, 255);
	gfx.PutPixel(x - 5, y - 4, 255, green, 255);
	gfx.PutPixel(x - 5, y - 3, 255, green, 255);
	gfx.PutPixel(x - 5, y + 3, 255, green, 255);
	gfx.PutPixel(x - 5, y + 4, 255, green, 255);
	gfx.PutPixel(x - 5, y + 5, 255, green, 255);

	// Vertical line (right)
	gfx.PutPixel(x + 5, y - 5, 255, green, 255);
	gfx.PutPixel(x + 5, y - 4, 255, green, 255);
	gfx.PutPixel(x + 5, y - 3, 255, green, 255);
	gfx.PutPixel(x + 5, y + 3, 255, green, 255);
	gfx.PutPixel(x + 5, y + 4, 255, green, 255);
	gfx.PutPixel(x + 5, y + 5, 255, green, 255);
}

void Box::SetGreen(const int value)
{
	green = value;
}