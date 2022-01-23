#include "error.hpp"
#include <system_error>
#include <iostream>
#include "stone.hpp"
#include "board.hpp"


int main()
{
  gomoku::Board board;


  std::cout << "init-------------" << std::endl;
  gomoku::types::Board& boa = board.get_board();
  gomoku::types::Board& boa_2 = board.get_board();
  std::cout << "iiii1" << std::endl;
  std::cout << std::hex << &boa << std::endl;
  std::cout << "iiii2" << std::endl;
  std::cout << std::hex << &boa_2 << std::endl;
  std::cout << "iiiiissss" << std::endl;
  std::cout << std::hex << &boa_2[1][1] << std::endl;

  std::cout << "iiii2assss" << std::endl;
  std::cout << std::hex << &boa[1][1] << std::endl;
  std::cout << "aaaaaaA" << std::endl;
  std::cout << 0 << std::endl;

  std::cout << "------------- list" << std::endl;
  std::cout << static_cast<int>(boa[1][1]) << std::endl;
  boa[1][1] = gomoku::Stone::black;
  std::cout << static_cast<int>(boa[1][1]) << std::endl;
  std::cout << static_cast<int>(boa_2[1][1]) << std::endl;

  std::cout << "-------------" << std::endl;
  try {
    // std::error_code ec = gomoku::make_error_code(gomoku::FutureErrc::invlid_stone_value);
    // throw std::system_error(ec, "system error");
  }
  catch(std::system_error& e) {
    std::cout << e.code().message() << std::endl;
  }
}
