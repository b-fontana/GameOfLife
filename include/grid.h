#include <iostream>
#include <array>

template <typename T>
class Grid {
public:
  enum class State {
	Dead = 0,
	Alive = 1
  };

private:
  constexpr inline
  int mStateCast(State state)
  {
	return static_cast<int>(state);
  }
  constexpr inline
  unsigned mTo1D(const unsigned x, const unsigned y) const
  {
	return y*mWidth + x;
  }

  constexpr static std::size_t mSizeT = sizeof(T);
  constexpr static unsigned mFactor = 2; //controls board size
  constexpr static unsigned mWidth = mFactor * mSizeT;
  constexpr static unsigned mHeight = mFactor * mSizeT;
  constexpr static unsigned mNcells = mWidth * mHeight;
  constexpr static unsigned mNelems = mNcells / mSizeT;
  std::array<T, mNelems> mArray;

public:
  Grid();
  ~Grid() {};

  auto operator()(const unsigned, const unsigned) const& -> const State&;
  auto set(State val, const unsigned, const unsigned) -> void;

  auto set(std::array<State, mNelems>) -> void;

  auto set_cell_state(const unsigned, const unsigned, State) -> void;
};


