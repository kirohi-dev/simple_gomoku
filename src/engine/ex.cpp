#include "error.hpp"
#include <system_error>
#include <iostream>
#include "stone.hpp"
#include "board.hpp"
#include "gomoku.hpp"


int main()
{
  gomoku::Gomoku engine;
  engine.game_start();
  engine.show_board();
}
