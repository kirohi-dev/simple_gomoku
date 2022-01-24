#ifndef GOMOKU_GOMOKU_H
#define GOMOKU_GOMOKU_H
#include "board.hpp"
#include "stone.hpp"

namespace gomoku {
  class Gomoku
  {
    private:
      Board board_;
      Stone turn;
      int moves;
      void turn_change();
    public:
      Gomoku();
      virtual ~Gomoku();
      void game_start();
      void set_stone(int row, int column);
      void show_board();
  };
}

#endif // GOMOKU_GOMOKU_H
