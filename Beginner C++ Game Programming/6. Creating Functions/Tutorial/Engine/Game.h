#pragma once

#include "Graphics.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Box.h"

class Game
{
public:
	Game(class MainWindow& wnd);
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
	
	void Go();

private:
	void ComposeFrame();
	void UpdateModel();

private:
	MainWindow & wnd;
	Graphics gfx;

	int xVelocity = 0;
	int yVelocity = 0;

	Box boxMovable;

	Box boxStationary0;
	Box boxStationary1;
	Box boxStationary2;
	Box boxStationary3;

	bool pressedLeft = false;
	bool pressedRight = false;
	bool pressedUp = false;
	bool pressedDown = false;
};