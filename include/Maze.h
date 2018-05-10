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

