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


namespace automaze
{
	Maze::Maze(int size_x, int size_y)
		: m_SizeX(size_x)
		, m_SizeY(size_y)
	{
		m_Board.resize(m_SizeX);
		for ( int i = 0 ; i < m_SizeX ; i ++ )
			m_Board[i].resize(m_SizeY);

		for ( int y = 0 ; y < m_SizeY ; y ++ )
			for ( int x = 0 ; x < m_SizeX ; x ++ )
				m_Board[x][y] = false;
	}

	bool Maze::IsWall(int x, int y)
	{
		return m_Board[x][y];
	}

	void Maze::SetWall(int x, int y)
	{
		m_Board[x][y] = true;
	}

	void Maze::RemoveWall(int x, int y)
	{
		m_Board[x][y] = false;
	}
}

