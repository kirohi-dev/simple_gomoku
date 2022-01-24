#ifndef GOMOKU_VALIDATOR_H
#define GOMOKU_VALIDATOR_H

#include "board.hpp"

namespace gomoku {
  class Validator
  {
    private:
      bool second_move(int moves, int row, int column);
      bool three_three(types::Board& board, int row, int column);
      bool four_four();
      bool too_long();
    public:
      Validator();
      virtual ~Validator();
      bool valid_set_stone();
  };

} // namespace gomoku

#endif // GOMOKU_VALIDATOR_H
