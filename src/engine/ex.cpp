#include "error.hpp"
#include <system_error>
#include <iostream>
#include "stone.hpp"
#include "board.hpp"


int main()
{
  gomoku::Board board;


  std::cout << "init-------------" << std::endl;
  gomoku::types::Board* boa = board.get_board();
  std::cout << "aaaaaaA" << std::endl;
  std::cout << 0 << std::endl;

  std::cout << "------------- list" << std::endl;
  std::cout << static_cast<int>(boa->board[1][1]) << std::endl;
  std::cout << static_cast<int>(boa->board[1][0]) << std::endl;
  std::cout << static_cast<int>(boa->board[0][1]) << std::endl;
  std::cout << static_cast<int>(boa->board[0][2]) << std::endl;
  std::cout << "-------------" << std::endl;
  try {
    for (int i = 0; i < 15; i++) {
      std::cout << static_cast<int>(boa->board[i][i]) << std::endl;
    }
    // std::error_code ec = gomoku::make_error_code(gomoku::FutureErrc::invlid_stone_value);
    // throw std::system_error(ec, "system error");
  }
  catch(std::system_error& e) {
    std::cout << e.code().message() << std::endl;
  }
}
