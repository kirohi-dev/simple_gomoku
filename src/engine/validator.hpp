#ifndef GOMOKU_VALIDATOR_H
#define GOMOKU_VALIDATOR_H

#include <vector>
#include "board.hpp"
#include "stone.hpp"

namespace gomoku {
  struct SurroundStones {
    std::vector<Stone> vertical;
    std::vector<Stone> horizontal;
    std::vector<Stone> upper_right;
    std::vector<Stone> upper_left;
  };

  class Validator
  {
    private:
      SurroundStones surround_stones;
      types::Board next_board;
      void set_surround_stones(int row, int column, types::Board& board);
      void probe_board(int row, int column, int right, int under,std::vector<Stone> direction, types::Board& board);
      bool second_move(int moves, int row, int column);
      bool three_three(int row, int column);
      bool four_four();
      bool too_long();
    public:
      Validator();
      virtual ~Validator();
      bool valid_stone(int moves, Stone turn,  int row, int column, types::Board& board);
  };

} // namespace gomoku

#endif // GOMOKU_VALIDATOR_H
