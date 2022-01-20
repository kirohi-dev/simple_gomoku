#ifndef GOMOKU_STONE_H
#define GOMOKU_STONE_H

#include <system_error>
#include "error.hpp"

namespace gomoku {
  enum class Stone : int {
    empty = 0,
    white = 1,
    black = 2
  };
} // namespace gomoku

#endif // GOMOKU_STONE_H
