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
	const int x = 700;
	const int y = 500;

	// Horizontal line
	gfx.PutPixel(x - 5, y, 255, 255, 255);
	gfx.PutPixel(x - 4, y, 255, 255, 255);
	gfx.PutPixel(x - 3, y, 255, 255, 255);
	gfx.PutPixel(x + 3, y, 255, 255, 255);
	gfx.PutPixel(x + 4, y, 255, 255, 255);
	gfx.PutPixel(x + 5, y, 255, 255, 255);
	
	// Vertical line
	gfx.PutPixel(x, y - 5, 255, 255, 255);
	gfx.PutPixel(x, y - 4, 255, 255, 255);
	gfx.PutPixel(x, y - 3, 255, 255, 255);
	gfx.PutPixel(x, y + 3, 255, 255, 255);
	gfx.PutPixel(x, y + 4, 255, 255, 255);
	gfx.PutPixel(x, y + 5, 255, 255, 255);
}