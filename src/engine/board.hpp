#ifndef GOMOKU_BOARD_H
#define GOMOKU_BOARD_H
#include "stone.hpp"

namespace gomoku {
  class Board
  {
    private:
      Stone board_[15][15];
      
    public:
      Board();
      virtual ~Board();
      void set_stone(Stone stone, int row, int column);
      Stone* get_board();
  };
} // namespace gomoku

#endif // GOMOKU_BOARD_H
