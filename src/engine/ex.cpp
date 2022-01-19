#include "error.hpp"
#include <system_error>
#include <iostream>
#include "stone.hpp"


int main()
{
  gomoku::stone st(1);
  std::cout << st.get() << std::endl;
  try {
    std::error_code ec = gomoku::make_error_code(gomoku::future_errc::invlid_stone_value);
    throw std::system_error(ec, "system error");
  }
  catch(std::system_error& e) {
    std::cout << e.code().message() << std::endl;
  }
}
