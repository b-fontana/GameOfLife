#include <iostream>
#include <array>
#include <utility>

template <typename T>
class Grid {
private:
  constexpr inline
  auto mTo1D(const unsigned x, const unsigned y) const -> unsigned
  {
	return y*mWidth + x;
  }
  inline auto north_west(const unsigned x, const unsigned y) -> bool
  {
	return this->operator()(x-1, y+1);
  }
  inline auto north(const unsigned x, const unsigned y) -> bool
  {
	return this->operator()(x, y+1);
  }
  inline auto east(const unsigned x, const unsigned y) -> bool
  {
	return this->operator()(x+1, y+1);
  }
  inline auto south_east(const unsigned x, const unsigned y) -> bool
  {
	return this->operator()(x, y+1);
  }
  inline auto south(const unsigned x, const unsigned y) -> bool
  {
	return this->operator()(x, y-1);
  }
  inline auto south_west(const unsigned x, const unsigned y) -> bool
  {
	return this->operator()(x-1, y-1);
  }
  inline auto west(const unsigned x, const unsigned y) -> bool
  {
	return this->operator()(x-1, y1);
  }
  constexpr static std::size_t mSizeT = sizeof(T);

public:
  Grid(const unsigned width, const unsigned height);
  ~Grid() {};

  auto operator()(const unsigned, const unsigned) const& -> const bool&;
  auto set(bool val, const unsigned, const unsigned) -> void;

  auto set(std::array<bool, mNelems>) -> void;

  auto set_cell_state(bool, const unsigned, const unsigned) -> void;
};


