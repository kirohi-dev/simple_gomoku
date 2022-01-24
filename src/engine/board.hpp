#ifndef GOMOKU_BOARD_H
#define GOMOKU_BOARD_H
#include <vector>
#include <array>
#include "stone.hpp"
#include <iostream>

namespace gomoku {
  namespace types {
    using Board = std::array<std::array<Stone, 15>, 15>;
  }
  

  class Board
  {
    private:
      types::Board board_;
      
    public:
      Board();
      virtual ~Board();
      void set_stone(Stone stone, int row, int column);
      types::Board& get_board();
  };
} // namespace gomoku


inline gomoku::Board::Board() {
  for (int i = 0;i < 15; i++) {
   for (int k = 0; k < 15; k++) {
     this->board_[i][k] = Stone::empty;
   }
  }
};

inline gomoku::Board::~Board() {};

inline void gomoku::Board::set_stone(Stone stone, int row, int column)
{
  this->board_[row][column] = stone;
}

inline gomoku::types::Board& gomoku::Board::get_board()
{
  return this->board_;
}

#endif // GOMOKU_BOARD_H
