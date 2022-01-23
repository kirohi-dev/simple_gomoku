#ifndef GOMOKU_BOARD_H
#define GOMOKU_BOARD_H
#include <vector>
#include <array>
#include "stone.hpp"
#include <iostream>

namespace gomoku {
  namespace types {
    struct Board {
      std::array<std::array<Stone, 15>, 15> board;
    };
  }

  class Board
  {
    private:
      types::Board board_;
      
    public:
      Board();
      virtual ~Board();
      void set_stone(Stone stone, int row, int column);
      types::Board* get_board();
  };
} // namespace gomoku

#endif // GOMOKU_BOARD_H

inline gomoku::Board::Board() {
  for (int i = 0;i < 15; i++) {
   for (int k = 0; k < 15; k++) {
     this->board_.board[i][k] = Stone::empty;
   }
  }
};

inline gomoku::Board::~Board() {};

inline void gomoku::Board::set_stone(Stone stone, int row, int column)
{
  this->board_.board[row][column] = stone;
}

inline gomoku::types::Board* gomoku::Board::get_board()
{
  return &board_;
}

