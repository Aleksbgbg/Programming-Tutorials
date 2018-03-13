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
	//// Horizontal line
	//gfx.PutPixel(695, 500, 255, 255, 255);
	//gfx.PutPixel(696, 500, 255, 255, 255);
	//gfx.PutPixel(697, 500, 255, 255, 255);
	//gfx.PutPixel(703, 500, 255, 255, 255);
	//gfx.PutPixel(704, 500, 255, 255, 255);
	//gfx.PutPixel(705, 500, 255, 255, 255);

	const int x = 5;
	
	// Vertical line
	gfx.PutPixel(x, 495, 255, 255, 255);
	gfx.PutPixel(x, 496, 255, 255, 255);
	gfx.PutPixel(x, 497, 255, 255, 255);
	gfx.PutPixel(x, 503, 255, 255, 255);
	gfx.PutPixel(x, 504, 255, 255, 255);
	gfx.PutPixel(x, 505, 255, 255, 255);
}