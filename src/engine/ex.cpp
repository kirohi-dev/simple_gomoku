#include "error.hpp"
#include <system_error>
#include <iostream>
#include "stone.hpp"


int main()
{
  gomoku::Stone st(gomoku::Color::empty);
  std::cout << static_cast<int>(st.get()) << std::endl;
  try {
    std::error_code ec = gomoku::make_error_code(gomoku::FutureErrc::invlid_stone_value);
    throw std::system_error(ec, "system error");
  }
  catch(std::system_error& e) {
    std::cout << e.code().message() << std::endl;
  }
}
