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

	boxMovable.SetPosition(ClampBoxHorizontal(boxMovable), ClampBoxVertical(boxMovable));

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

int Game::ClampBoxHorizontal(const Box& box)
{
	if (box.GetX() < Box::CenterBorderDistance)
	{
		return Box::CenterBorderDistance;
	}

	if (box.GetX() >= Graphics::ScreenWidth - Box::CenterBorderDistance)
	{
		return Graphics::ScreenWidth - Box::CenterBorderDistance - 1;
	}

	return box.GetX();
}

int Game::ClampBoxVertical(const Box& box)
{
	if (box.GetY() < Box::CenterBorderDistance)
	{
		return Box::CenterBorderDistance;
	}

	if (box.GetY() >= Graphics::ScreenHeight - Box::CenterBorderDistance)
	{
		return Graphics::ScreenHeight - Box::CenterBorderDistance - 1;
	}

	return box.GetY();
}

void Game::ComposeFrame()
{
	boxMovable.Draw(gfx);

	boxStationary0.Draw(gfx);
	boxStationary1.Draw(gfx);
	boxStationary2.Draw(gfx);
	boxStationary3.Draw(gfx);
}