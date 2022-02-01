#include "validator.hpp"
#include "board.hpp"
#include "stone.hpp"

void gomoku::Validator::set_surround_stones(int row, int column, types::Board& board)
{
  // vertical
  this->probe_board(row, column, 1, 0, this->surround_stones.vertical, board);
  // horizontal
  this->probe_board(row, column, 0, 1, this->surround_stones.horizontal, board);
  // upper_right
  this->probe_board(row, column, 1, 1, this->surround_stones.upper_right, board);
  // upper_left
  this->probe_board(row, column, 1, -1, this->surround_stones.upper_left, board);
}

void gomoku::Validator::probe_board(int row, int column, int right, int under, std::vector<Stone> direction, types::Board& board)
{
  // init direction
  direction = {};
  // forward
  // 空いている場所が3❎3になる場合は白にする
  // emptyがあったら、再起呼び出し
  int empty_num = 0;
  bool finish_loop = false;
  for (int i = row; i < board.size(); i += right) {
    for (int k = column; k < board[i].size(); k += under) {
      gomoku::Stone target = board[i][k];
      if (target == gomoku::Stone::white) {
        direction.push_back(target);
        finish_loop = true;
        break;
      }
      if (target == gomoku::Stone::empty) {
        empty_num += 1;
        if (empty_num < 2) {
          direction.push_back(target);
        }
        else {
          finish_loop = true;
          break;
        }
      }
      if (target == gomoku::Stone::black) {
        direction.push_back(target);
      }
    }
    if (finish_loop == true) {
      break;
    }
  }
  // reverse
  empty_num = 0;
  finish_loop = false;
  for (int c = row - 1; c >= 0; c -= right) {
    for (int j = column =1; j >= 0; j -= under) {
      gomoku::Stone target = board[c][j];
      if (target == gomoku::Stone::white) {
        direction.insert(direction.begin(), target);
        finish_loop = true;
        break;
      }
      if (target == gomoku::Stone::empty) {
        empty_num += 1;
        if (empty_num < 2) {
          direction.insert(direction.begin(), target);
        }
        else {
          finish_loop = true;
          break;
        }
      }
      if (target == gomoku::Stone::black) {
        direction.insert(direction.begin(), target);
      }
    }
    if (finish_loop == true) {
      break;
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

bool gomoku::Validator::three_three(int row, int column)
{
  // 両端が白と白で、間が5の場合
  // 単純に3となる,片方から見るだけでOK
}

bool gomoku::Validator::four_four()
{
  // 両端が白と白で、間が5の場合
  // 単純に4となる(りょうじゅん見る)
}

bool gomoku::Validator::valid_stone(int moves, Stone turn,  int row, int column, types::Board& board)
{
  if (!this->second_move(moves, row, column)) return false;
  if (turn == Stone::white) return true;
}
