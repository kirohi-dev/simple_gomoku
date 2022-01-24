#include <iostream>
#include <string>
#include "gomoku.hpp"
#include "board.hpp"
#include "stone.hpp"

void gomoku::Gomoku::turn_change()
{
  // change turn
  if (this->turn == Stone::black) this->turn = Stone::white;
  else this->turn = Stone::black;
  // add moves
  this->moves++;
}

gomoku::Gomoku::Gomoku()
{
  this->board_ = Board();
  this->turn = Stone::black;
  this->moves = 0;
}

gomoku::Gomoku::~Gomoku() {};


void gomoku::Gomoku::game_start()
{
  this->board_.set_stone(this->turn, 7, 7);
  this->turn_change();
}

void gomoku::Gomoku::set_stone(int row, int column)
{
  this->board_.set_stone(this->turn, row, column);
  this->turn_change();
}

void gomoku::Gomoku::show_board()
{
  for (int i = 0; i < this->board_.get_board().size(); i++) {
    std::string row;
    for (int k = 0; k < this->board_.get_board()[i].size(); k++) {
      row += std::to_string(static_cast<int>(this->board_.get_board()[i][k]));
    }
    std::cout << i << " : " << row << std::endl;
  }
}
