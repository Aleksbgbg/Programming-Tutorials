#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	boxMovable{ 250, 250 },
	boxStationary{ 250, 250 }
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

	boxMovable.MoveBy(xVelocity, yVelocity);

	boxStationary.SetGreen(boxMovable.IsCollision(boxStationary) ? 0 : 255);
}

void Game::ComposeFrame()
{
	boxMovable.Draw(gfx);
	boxStationary.Draw(gfx);
}