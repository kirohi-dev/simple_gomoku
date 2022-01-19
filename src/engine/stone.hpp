#ifndef GOMOKU_STONE_H
#define GOMOKU_STONE_H

#include <system_error>
#include "error.hpp"

namespace gomoku {
  class stone
  {
    private:
      int color_value_; // 0: empty, 1: white, 2: black
      bool validate(int color_value);
      
    public:
      stone(int color_value);
      virtual ~stone();
      int get() const noexcept;
      void set(int color_value);
  };
} // namespace gomoku

inline gomoku::stone::stone(int color_value)
{
  if (!this->validate(color_value))
  {
    std::error_code ec = make_error_code(gomoku::future_errc::invlid_stone_value);
    throw std::system_error{ec};
  }
  this->color_value_ = color_value;
}

inline gomoku::stone::~stone(){};

inline void gomoku::stone::set(int color_value)
{
  if (!this->validate(color_value))
  {
    std::error_code ec = make_error_code(gomoku::future_errc::invlid_stone_value);
    throw std::system_error{ec};
  }
  this->color_value_ = color_value;
}

inline bool gomoku::stone::validate(int color_value)
{
  if (color_value == 1 || color_value == 2 || color_value == 0) return true;
  return false;
}

inline int gomoku::stone::get() const noexcept
{
  return this->color_value_;
}

#endif // GOMOKU_STONE_H
