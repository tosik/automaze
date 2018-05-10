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

