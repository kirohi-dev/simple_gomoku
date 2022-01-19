#ifndef GOMOKU_ERROR_H
#define GOMOKU_ERROR_H

#include <system_error>

namespace gomoku {
  enum class future_errc : int {
    invlid_stone_value = 1
  };
  
  std::error_code make_error_code(future_errc e) noexcept;
}

#endif // GOMOKU_ERROR_H
