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
	// Horizontal line
	gfx.PutPixel(395, 300, 255, 255, 255);
	gfx.PutPixel(396, 300, 255, 255, 255);
	gfx.PutPixel(397, 300, 255, 255, 255);
	gfx.PutPixel(403, 300, 255, 255, 255);
	gfx.PutPixel(404, 300, 255, 255, 255);
	gfx.PutPixel(405, 300, 255, 255, 255);
	
	// Vertical line
	gfx.PutPixel(400, 295, 255, 255, 255);
	gfx.PutPixel(400, 296, 255, 255, 255);
	gfx.PutPixel(400, 297, 255, 255, 255);
	gfx.PutPixel(400, 303, 255, 255, 255);
	gfx.PutPixel(400, 304, 255, 255, 255);
	gfx.PutPixel(400, 305, 255, 255, 255);
}