	/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include "SpriteCodex.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	rng(std::random_device()()),
	brd(gfx),
	snek({2,2}),
	goal(rng,brd,snek)
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
	if (isStarted)
	{
		if (!isGameOver)
		{
			if (wnd.kbd.KeyIsPressed(VK_UP))
			{
				loc = { 0,-1 };
			}
			if (wnd.kbd.KeyIsPressed(VK_DOWN))
			{
				loc = { 0, 1 };
			}
			if (wnd.kbd.KeyIsPressed(VK_LEFT))
			{
				loc = { -1, 0 };
			}
			if (wnd.kbd.KeyIsPressed(VK_RIGHT))
			{
				loc = { 1, 0 };
			}
			if (++nCount >= nCountMax)
			{
				nCount = 0;
				if (!brd.isInsideGrid(snek.GetNextHeadLocation(loc)) || snek.isBitedSelf())
				{
					isGameOver = true;
				}
				else
				{
					bool isEating = snek.isBitedGoal(goal);
					if (isEating)
					{
						if (nCountMax > 4)
						{
							nCountMax -= speedup;
						}
						snek.Grow();
					}
					snek.MoveBy(loc);
					if (isEating)
					{
						goal.ReSpawn(rng, brd, snek);
					}
				}
			}
		}
	}
	else
	{
		if (wnd.kbd.KeyIsPressed(VK_RETURN))
		{
			isStarted = true;
		}
	}
}

void Game::ComposeFrame()
{
	if (isStarted)
	{
		if (isGameOver)
		{
			SpriteCodex::DrawGameOver(358, 268, gfx);
		}
		brd.DrawBoundry();
		snek.Draw(brd);
		goal.Draw(brd);
	}
	else
	{
		SpriteCodex::DrawTitle(290, 225, gfx);
	}
}
