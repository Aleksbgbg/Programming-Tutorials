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
}

void Game::ComposeFrame()
{
	int x = 400;
	int y = 300;
	
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		x -= 100;
	}
	else if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		x += 100;
	}

	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		y -= 100;
	}
	else if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		y += 100;
	}

	const int green = wnd.kbd.KeyIsPressed(VK_CONTROL) ? 0 : 255;

	if (wnd.kbd.KeyIsPressed(VK_SHIFT)) // Box
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