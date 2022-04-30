#include "include/game_of_life.h"

void GameOfLife::launch() {
}

void GameOfLife::tick() {
}

Grid::State mApplyRulesToCell(const unsigned x, const unsigned y)
{
  if(x>=mWidth or y>=mHeight)
	throw std::invalid_argument("Trying to access a position outside the grid.");

  unsigned counter = 0;
  
  bool thisCell  = grid(x, y);
  
  //right top; corner
  if (x==mWidth-1 and y==mHeight-1)
	{
	  counter = ( static_cast<unsigned>(grid.west(x, y)) +
				  static_cast<unsigned>(grid.south_west(x, y)) +
				  static_cast<unsigned>(grid.south(x, y)) )
	}

  ETC!!!!!!!!!!
  // Grid::State nw = grid(x-1, y+1);
  // Grid::State n  = grid(x, y+1);
  // Grid::State ne = grid(x+1, y+1);
  // Grid::State e  = grid(x+1, y);
  // Grid::State se = grid(x+1, y-1);
  // Grid::State s  = grid(x, y-1);
  // Grid::State sw = grid(x-1, y-1);
  // Grid::State w  = grid(x-1, y);
}
