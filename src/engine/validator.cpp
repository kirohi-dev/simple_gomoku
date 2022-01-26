#include "validator.hpp"
#include "board.hpp"
#include "stone.hpp"

void gomoku::Validator::set_surround_stones(int row, int column, types::Board& board)
{
  // vertical

}

void gomoku::Validator::probe_board(int row, int column, int right, int under, std::vector<Stone> direction, types::Board& board)
{
  // init direction
  direction = {};
  // forward
  for (int i = row; i < board.size(); i += right) {
    for (int k = column; k < board[i].size(); k += under) {
      direction.push_back(board[i][k]);
    }
  }
  // reverse
  for (int c = row - 1; c >= 0; c -= right) {
    for (int j = column =1; j >= 0; j -= under) {
      direction.insert(direction.begin(), board[c][j]);
    }
  }
}

bool gomoku::Validator::second_move(int moves, int row, int column)
{
  if (
      moves == 2
      && 6 <= row <= 8
      && 6 <= column <= 8
    ) {
      return true;
    }
  return false;
}

bool gomoku::Validator::three_three(types::Board& board, int row, int column)
{
  
}

bool gomoku::Validator::valid_stone(int moves, Stone turn,  int row, int column, types::Board& board)
{
  if (!this->second_move(moves, row, column)) return false;
  if (turn == Stone::white) return true;
}
