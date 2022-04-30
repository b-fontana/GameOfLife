#include "include/grid.h"
#include <cstdint>
#include <stdexcept>

Grid::Grid() {
  set();
}

Grid::Grid(const unsigned width, const unsigned height)
  : mWidth(width), mHeight(height)
{
  const unsigned mNcells = mWidth * mHeight;
  const unsigned mNelems = mNcells / mSizeT;
  std::vector<T> mArray(mNelems);
}

void Grid::set(std::array<bool, mNCells> vals) {
  for (std::size_t i=0; i<mNCells; ++i)
	mArray[i] = mboolCast(vals[i]);
}

//https://isocpp.org/wiki/faq/operator-overloading#matrix-subscript-op
auto Grid::operator()(const unsigned x, const unsigned y) const& -> const bool&
{
  unsigned pos = mGetCellGlobalCoordinate(x, y);
  const auto [q, r] = std::div(pos, mSizeT);
  T elem = mArray[pos];
  T mask = 0x1 << r;
  if( (mask & elem) == 0x0)
	return false;
  return true;
}

auto Grid<std::uint8_t>::mGetCellGlobalCoordinate(const unsigned x, const unsigned y) const& -> unsigned
{
  if (x >= mWidth or y >= mHeight)
	throw std::invalid_argument("Trying to access a position outside the grid.")
  unsigned pos = mTo1D(x, y);
  return pos;
}
auto Grid::set(bool val, const unsigned, const unsigned) -> void;
{
  unsigned pos = mTo1D(x, y);
  const auto [q, r] = std::div(pos, mSizeT);
  T mask = 0x1 << r;
  // setting
  if (val == true)
	mArray[pos] |= mask;
  // clearing
  else if (val == false)
	mArray[pos] &= ~mask;
}

auto Grid::set_cell_state(const unsigned x, const unsigned y, bool state) -> void
{
  unsigned pos = mTo1D(x, y);
  if(pos>=mNCells or pos<0)
	std::cout << "[Grid::set] Out-of-bounds grid access (" << pos << ")" << "\n";
  mArray[pos] = state;
}
