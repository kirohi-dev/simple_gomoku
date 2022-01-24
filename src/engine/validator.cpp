#include "validator.hpp"
#include "board.hpp"

bool gomoku::Validator::second_move(int moves, int row, int column)
{
  if (
      moves == 2
      && 6 <= row <= 8
      && 6 <= column <= 8
    ) {
      return false;
    }
  return true;
}

bool gomoku::Validator::three_three(types::Board& board, int row, int column)
{
  
}
