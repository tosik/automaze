#include "Maze.h"
#include "Boutaoshi.h"
#include <iostream>


int main(void)
{
	automaze::Maze maze(31, 21);
	automaze::Boutaoshi::generateMaze(maze);

	for ( int y = 0 ; y < (int)maze.GetSizeY() ; y ++ )
	{
		for ( int x = 0 ; x < (int)maze.GetSizeX() ; x ++ )
		{
			if ( maze.IsWall(x, y))
				std::cout << "%%";
			else
				std::cout << "  ";
		}
		std::cout << std::endl;
	}
}

