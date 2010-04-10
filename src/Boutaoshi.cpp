/*
 * automaze. Maze generation engine.
 * Copyright (C) Toshiyuki Hirooka <toshi.hirooka@gmail.com> http://wasabi.in/
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

#include "Maze.h"
#include <cstdlib>

namespace automaze
{
	namespace Boutaoshi
	{
		void initialize(Maze & maze)
		{
			for ( int y = 0 ; y < (int)maze.GetSizeY() ; y ++ )
			{
				for ( int x = 0 ; x < (int)maze.GetSizeX() ; x ++ )
				{
					if ( x == 0 || x == maze.GetSizeX() - 1 ||
						y == 0 || y == maze.GetSizeY() - 1 )
						maze.SetWall(x, y);

					if ( (x%2) == 0 && (y%2) == 0 )
						maze.SetWall(x, y);
				}
			}
		}

		bool IsWall(Maze & maze, int x, int y, int direction)
		{
			int rx, ry;
			switch ( direction )
			{
				case 0:
					rx = -1;
					ry = 0;
					break;

				case 1:
					rx = 1;
					ry = 0;
					break;

				case 2:
					rx = 0;
					ry = -1;
					break;

				case 3:
					rx = 0;
					ry = 1;
					break;
			}

			return maze.IsWall(x + rx, y + ry);
		}

		void SetWall(Maze & maze, int x, int y, int direction)
		{
			int rx, ry;
			switch ( direction )
			{
				case 0:
					rx = -1;
					ry = 0;
					break;

				case 1:
					rx = 1;
					ry = 0;
					break;

				case 2:
					rx = 0;
					ry = -1;
					break;

				case 3:
					rx = 0;
					ry = 1;
					break;
			}

			maze.SetWall(x + rx, y + ry);
		}

		void generateMaze(Maze & maze)
		{
			initialize(maze);

			// first line (y==2)
			for ( int x = 2, y = 2 ; x < maze.GetSizeX() - 2 ; x += 2 )
			{
				int direction;
				for ( direction = rand() % 4 ;
						IsWall(maze, x, y, direction) ;
						direction = rand() % 4 )
				{
				}
				SetWall(maze, x, y, direction);
			}

			// other lines (y!=2)
			for ( int y = 4 ; y < maze.GetSizeY() - 2; y += 2 )
			{
				for ( int x = 2 ; x < maze.GetSizeX() - 2; x += 2 )
				{
					int direction;
					for ( direction = rand() % 3 + 1 ;
							IsWall(maze, x, y, direction) ;
							direction = rand() % 3 + 1 )
					{
					}
					SetWall(maze, x, y, direction);
				}
			}
		}

	}
}

