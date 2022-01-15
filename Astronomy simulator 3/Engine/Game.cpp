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
#include <chrono>

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	earth(vec2d(0.0f, 400.0f), vec2d(10.0f, 0.0f), 100.0f, 10.0f),
	earth2(vec2d(300.0f, 255.0f), vec2d(10.0f, 30.0f), 100.0f, 10.0f),
	venus(vec2d(500.0f, 700.0f), vec2d(0.0f, -20.0f), 50.0f, 5.0f)
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
	float dt = ft.mark();

	earth.update(dt, venus);
	earth.update(dt, earth2);

	earth2.update(dt, earth);
	earth2.update(dt, venus);

	venus.update(dt, earth);
	venus.update(dt, earth2);
}

void Game::ComposeFrame()
{
	earth.draw(gfx);
	earth2.draw(gfx);
	venus.draw(gfx);
}
