#include "include/grid.h"

Grid::Grid() {
  set();
}

void Grid::set(std::array<State, mNCells> vals) {
  for (std::size_t i=0; i<mNCells; ++i)
	mArray[i] = mStateCast(vals[i]);
}

//https://isocpp.org/wiki/faq/operator-overloading#matrix-subscript-op
auto Grid::operator()(const unsigned x, const unsigned y) const& -> const State&
{
  unsigned pos = mTo1D(x, y);
  const auto [q, r] = std::div(pos, mSizeT);
  T elem = mArray[pos];
  T mask = 0x1 << r;
  if( (mask & elem) == 0x0)
	return State::Dead;
  return State:Alive;
}

auto Grid::set(State val, const unsigned, const unsigned) -> void;
{
  unsigned pos = mTo1D(x, y);
  const auto [q, r] = std::div(pos, mSizeT);
  T mask = 0x1 << r;
  // setting
  if (val == State::Alive)
	mArray[pos] |= mask;
  // clearing
  else if (val == State::Dead)
	mArray[pos] &= ~mask;
}

auto Grid::set_cell_state(const unsigned x, const unsigned y, State state) -> void
{
  unsigned pos = mTo1D(x, y);
  if(pos>=mNCells or pos<0)
	std::cout << "[Grid::set] Out-of-bounds grid access (" << pos << ")" << "\n";
  mArray[pos] = mStateCast(state);
}
