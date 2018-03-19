#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd)
{
}

void Game::Go()
{
	gfx.BeginFrame();
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		xVelocity -= 3;
	}
	else if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		xVelocity += 3;
	}

	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		yVelocity -= 3;
	}
	else if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		yVelocity += 3;
	}

	x += xVelocity;
	y += yVelocity;

	green = wnd.kbd.KeyIsPressed(VK_CONTROL) ? 0 : 255;

	shapeIsChanged = wnd.kbd.KeyIsPressed(VK_SHIFT);
}

void Game::ComposeFrame()
{
	if (shapeIsChanged) // Box
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
	else // Reticle
	{
		// Horizontal line
		gfx.PutPixel(x - 5, y, 255, green, 255);
		gfx.PutPixel(x - 4, y, 255, green, 255);
		gfx.PutPixel(x - 3, y, 255, green, 255);
		gfx.PutPixel(x + 3, y, 255, green, 255);
		gfx.PutPixel(x + 4, y, 255, green, 255);
		gfx.PutPixel(x + 5, y, 255, green, 255);

		// Vertical line
		gfx.PutPixel(x, y - 5, 255, green, 255);
		gfx.PutPixel(x, y - 4, 255, green, 255);
		gfx.PutPixel(x, y - 3, 255, green, 255);
		gfx.PutPixel(x, y + 3, 255, green, 255);
		gfx.PutPixel(x, y + 4, 255, green, 255);
		gfx.PutPixel(x, y + 5, 255, green, 255);
	}
}