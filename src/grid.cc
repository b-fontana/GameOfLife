#include "include/grid.h"

Grid::Grid() {
  set();
}

void Grid::set() {
  std::fill(begin(mArray), end(mArray), _cast(State::Dead));
}

void Grid::set(std::array<State, mNCells> vals) {
  for (std::size_t i=0; i<mNCells; ++i)
	mArray[i] = _cast(vals[i]);
}

//https://isocpp.org/wiki/faq/operator-overloading#matrix-subscript-op
int& Grid::operator()(const unsigned x, const unsigned y) {
  unsigned pos = _to_1D(x, y);
  return mArray[pos];
}

int& Grid::at(const unsigned x, const unsigned y) {
  unsigned pos = _to_1D(x, y);
  if(pos>=mNCells or pos<0)
	std::cout << "[Grid::at] Out-of-bounds grid access (" << pos << ")" << "\n";
  return mArray[pos];
}

void Grid::set_cell_state(const unsigned x, const unsigned y, State state) {
  unsigned pos = _to_1D(x, y);
  if(pos>=mNCells or pos<0)
	std::cout << "[Grid::set] Out-of-bounds grid access (" << pos << ")" << "\n";
  mArray[pos] = _cast(state);
}
