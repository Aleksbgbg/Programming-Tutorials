#include <random>

#include "MainWindow.h"
#include "Game.h"
#include "SpriteCodex.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd)
{
	std::mt19937 randomEngine{ std::random_device{ }() };

	const std::uniform_int_distribution<int> dudeHorizontalDistribution{ 0, Graphics::ScreenWidth - DudeDimension - 1 };
	const std::uniform_int_distribution<int> dudeVerticalDistribution{ 0, Graphics::ScreenHeight - DudeDimension - 1 };

	dudeX = dudeHorizontalDistribution(randomEngine);
	dudeY = dudeVerticalDistribution(randomEngine);

	const std::uniform_int_distribution<int> pooHorizontalDistribution{ 0, Graphics::ScreenWidth - PooDimension - 1 };
	const std::uniform_int_distribution<int> pooVerticalDistribution{ 0, Graphics::ScreenHeight - PooDimension - 1 };

	poo0X = pooHorizontalDistribution(randomEngine);
	poo0Y = pooVerticalDistribution(randomEngine);

	poo1X = pooHorizontalDistribution(randomEngine);
	poo1Y = pooVerticalDistribution(randomEngine);

	poo2X = pooHorizontalDistribution(randomEngine);
	poo2Y = pooVerticalDistribution(randomEngine);

	const std::uniform_int_distribution<int> velocityDistribution{ 0, 1 };

	poo0VelocityX = velocityDistribution(randomEngine) == 0 ? -1 : 1;
	poo0VelocityY = velocityDistribution(randomEngine) == 0 ? -1 : 1;

	poo1VelocityX = velocityDistribution(randomEngine) == 0 ? -1 : 1;
	poo1VelocityY = velocityDistribution(randomEngine) == 0 ? -1 : 1;

	poo2VelocityX = velocityDistribution(randomEngine) == 0 ? -1 : 1;
	poo2VelocityY = velocityDistribution(randomEngine) == 0 ? -1 : 1;
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
		dudeX -= 1;
	}

	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		dudeX += 1;
	}

	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		dudeY -= 1;
	}

	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		dudeY += 1;
	}

	dudeX = ClampScreenX(dudeX, DudeDimension);
	dudeY = ClampScreenY(dudeY, DudeDimension);

	if (isGameOver)
	{
		return;
	}

	if (IsOutOfBounds(poo0X, PooDimension, Graphics::ScreenWidth))
	{
		poo0VelocityX = -poo0VelocityX;
	}

	if (IsOutOfBounds(poo0Y, PooDimension, Graphics::ScreenHeight))
	{
		poo0VelocityY = -poo0VelocityY;
	}

	if (IsOutOfBounds(poo1X, PooDimension, Graphics::ScreenWidth))
	{
		poo1VelocityX = -poo1VelocityX;
	}

	if (IsOutOfBounds(poo1Y, PooDimension, Graphics::ScreenHeight))
	{
		poo1VelocityY = -poo1VelocityY;
	}

	if (IsOutOfBounds(poo2X, PooDimension, Graphics::ScreenWidth))
	{
		poo2VelocityX = -poo2VelocityX;
	}

	if (IsOutOfBounds(poo2Y, PooDimension, Graphics::ScreenHeight))
	{
		poo2VelocityY = -poo2VelocityY;
	}

	poo0X += poo0VelocityX;
	poo0Y += poo0VelocityY;

	poo1X += poo1VelocityX;
	poo1Y += poo1VelocityY;

	poo2X += poo2VelocityX;
	poo2Y += poo2VelocityY;

	if (!poo0IsEaten && Overlap(dudeX, dudeY, DudeDimension, DudeDimension, poo0X, poo0Y, PooDimension, PooDimension))
	{
		poo0IsEaten = true;
	}

	if (!poo1IsEaten && Overlap(dudeX, dudeY, DudeDimension, DudeDimension, poo1X, poo1Y, PooDimension, PooDimension))
	{
		poo1IsEaten = true;
	}

	if (!poo2IsEaten && Overlap(dudeX, dudeY, DudeDimension, DudeDimension, poo2X, poo2Y, PooDimension, PooDimension))
	{
		poo2IsEaten = true;
	}

	if (poo0IsEaten && poo1IsEaten && poo2IsEaten)
	{
		isGameOver = true;
	}
}

bool Game::Overlap(const int x0, const int y0, const int width0, const int height0, const int x1, const int y1, const int width1, const int height1) const
{
	const int firstLeft = x0;
	const int firstTop = y0;
	const int firstRight = x0 + width0;
	const int firstBottom = y0 + height0;

	const int secondLeft = x1;
	const int secondTop = y1;
	const int secondRight = x1 + width1;
	const int secondBottom = y1 + height1;

	return firstLeft <= secondRight && secondLeft <= firstRight &&
		   firstTop <= secondBottom && secondTop <= firstBottom;
}

int Game::ClampScreenX(const int x, const int width) const
{
	return ClampScreen(x, width, Graphics::ScreenWidth);
}

int Game::ClampScreenY(const int y, const int height) const
{
	return ClampScreen(y, height, Graphics::ScreenHeight);
}

int Game::ClampScreen(const int position, const int dimension, const int furthestPosition) const
{
	if (position < 0)
	{
		return 0;
	}

	if (position + dimension >= furthestPosition)
	{
		return furthestPosition - dimension;
	}

	return position;
}

bool Game::IsOutOfBounds(const int position, const int dimension, const int furthestPosition) const
{
	return 0 >= position || position + dimension >= furthestPosition;
}

void Game::ComposeFrame()
{
	SpriteCodex::DrawDude(gfx, dudeX, dudeY);

	if (isGameOver)
	{
		SpriteCodex::DrawGameOver(gfx, 280, 232);
		return;
	}

	if (!poo0IsEaten)
	{
		SpriteCodex::DrawPoo(gfx, poo0X, poo0Y);
	}

	if (!poo1IsEaten)
	{
		SpriteCodex::DrawPoo(gfx, poo1X, poo1Y);
	}

	if (!poo2IsEaten)
	{
		SpriteCodex::DrawPoo(gfx, poo2X, poo2Y);
	}
}
