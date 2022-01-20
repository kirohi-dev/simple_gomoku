#ifndef GOMOKU_STONE_H
#define GOMOKU_STONE_H

#include <system_error>
#include "error.hpp"

namespace gomoku {
  enum class Color : int {
    empty = 0,
    white = 1,
    black = 2
  };

  class Stone
  {
    private:
      Color color_value_;
      
    public:
      Stone(Color color_value);
      virtual ~Stone();
      Color get() const noexcept;
      void set(Color color_value);
  };
} // namespace gomoku

inline gomoku::Stone::Stone(Color color_value)
{
  this->color_value_ = color_value;
}

inline gomoku::Stone::~Stone(){};

inline void gomoku::Stone::set(Color color_value)
{
  this->color_value_ = color_value;
}

inline gomoku::Color gomoku::Stone::get() const noexcept
{
  return this->color_value_;
}

#endif // GOMOKU_STONE_H
