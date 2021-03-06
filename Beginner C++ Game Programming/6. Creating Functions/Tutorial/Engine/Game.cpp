#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	boxMovable{ 250, 250 },
	boxStationary0{ 350, 350 },
	boxStationary1{ 400, 400 },
	boxStationary2{ 250, 550 },
	boxStationary3{ 450, 110 }
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
		boxMovable.MoveBy(-1, 0);
	}
	
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		boxMovable.MoveBy(1, 0);
	}

	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		boxMovable.MoveBy(0, -1);
	}
	
	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		boxMovable.MoveBy(0, 1);
	}

	if (boxMovable.IsCollision(boxStationary0) ||
		boxMovable.IsCollision(boxStationary1) ||
		boxMovable.IsCollision(boxStationary2) ||
		boxMovable.IsCollision(boxStationary3))
	{
		boxMovable.SetGreen(0);
	}
	else
	{
		boxMovable.SetGreen(255);
	}
}

void Game::ComposeFrame()
{
	boxMovable.Draw(gfx);

	boxStationary0.Draw(gfx);
	boxStationary1.Draw(gfx);
	boxStationary2.Draw(gfx);
	boxStationary3.Draw(gfx);
}