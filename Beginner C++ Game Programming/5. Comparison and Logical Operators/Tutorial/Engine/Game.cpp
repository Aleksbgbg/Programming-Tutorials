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
		if (!pressedLeft)
		{
			xVelocity -= 1;
			pressedLeft = true;
		}
	}
	else
	{
		pressedLeft = false;
	}
	
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		if (!pressedRight)
		{
			xVelocity += 1;
			pressedRight = true;
		}
	}
	else
	{
		pressedRight = false;
	}

	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		if (!pressedUp)
		{
			yVelocity -= 1;
			pressedUp = true;
		}
	}
	else
	{
		pressedUp = false;
	}
	
	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		if (!pressedDown)
		{
			yVelocity += 1;
			pressedDown = true;
		}
	}
	else
	{
		pressedDown = false;
	}

	x += xVelocity;
	y += yVelocity;

	if (x - 5 < 0)
	{
		x = 5;
		xVelocity = 0;
	}
	else if (x + 5 > Graphics::ScreenWidth - 1)
	{
		x = Graphics::ScreenWidth - 6;
		xVelocity = 0;
	}
	
	if (y - 5 < 0)
	{
		y = 5;
		yVelocity = 0;
	}
	else if (y + 5 > Graphics::ScreenHeight - 1)
	{
		y = Graphics::ScreenHeight - 6;
		yVelocity = 0;
	}

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