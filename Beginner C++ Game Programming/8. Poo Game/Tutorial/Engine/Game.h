#pragma once

#include "Graphics.h"
#include "Keyboard.h"
#include "Mouse.h"

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
	bool Overlap(const int x0, const int y0, const int width0, const int height0, const int x1, const int y1, const int width1, const int height1) const;

	int ClampScreenX(const int x, const int width) const;
	int ClampScreenY(const int y, const int height) const;

	int ClampScreen(const int position, const int dimension, const int furthestPosition) const;

private:
	MainWindow& wnd;
	Graphics gfx;

private:
	static constexpr int DudeDimension = 20;
	static constexpr int PooDimension = 24;

private:
	bool isGameOver = false;

	int dudeX;
	int dudeY;

	int poo0X;
	int poo0Y;

	int poo1X;
	int poo1Y;

	int poo2X;
	int poo2Y;

	bool poo0IsEaten = false;
	bool poo1IsEaten = false;
	bool poo2IsEaten = false;
};