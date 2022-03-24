#include "include/grid.h"

class GameOfLife {
 public:
  void launch();
  void tick();

 private:
  Grid grid;
};
