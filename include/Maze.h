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


#pragma once

#include <vector>

namespace automaze
{
	typedef std::vector<std::vector<bool> > Board; // caution : using vector<bool>

	class Maze
	{
		public:
			Maze(int size_x, int size_y);

			bool IsWall(int x, int y);

			int GetSizeX() { return m_SizeX; }
			int GetSizeY() { return m_SizeY; }

			void SetWall(int x, int y);
			void RemoveWall(int x, int y);

		private:
			int m_SizeX, m_SizeY;
			Board m_Board;
	};
}
