#include <iostream>
#include <array>

class Grid {
public:
  enum class State {
	Dead = 0,
	Alive = 1
  };

private:
  constexpr int _cast(State state) {
	return static_cast<int>(state);
  }
  constexpr unsigned _to_1D(const unsigned x, const unsigned y) {
	return y*mWidth + x;
  }
  
  constexpr static unsigned mWidth=80;
  constexpr static unsigned mHeight=80;
  constexpr static unsigned mNCells=mWidth*mHeight;
  std::array<int, mNCells> mArray;

public:
  Grid();
  ~Grid() {};

  int& operator()(const unsigned, const unsigned);
  int& at(const unsigned, const unsigned);

  void set();
  void set(std::array<State, mNCells>);

  void set_cell_state(const unsigned, const unsigned, State);
};


