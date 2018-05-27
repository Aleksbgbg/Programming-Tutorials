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

	static int ClampBoxHorizontal(const Box& box);
	static int ClampBoxVertical(const Box& box);

private:
	MainWindow & wnd;
	Graphics gfx;

	Box boxMovable;

	Box boxStationary0;
	Box boxStationary1;
	Box boxStationary2;
	Box boxStationary3;
};