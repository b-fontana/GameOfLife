#include "include/grid.h"
#include <cstdint>

class GameOfLife {
 public:
  void launch();
  void tick();

 private:
  Grid<std::uint8_t> grid;
  Grid::State mApplyRulesToCell(const unsigned x, const unsigned y);
};
