#ifndef GOMOKU_ERROR_H
#define GOMOKU_ERROR_H

#include <system_error>

namespace gomoku {
  enum class FutureErrc : int {
    invlid_stone_value = 1
  };
  
  std::error_code make_error_code(FutureErrc e) noexcept;
}

#endif // GOMOKU_ERROR_H
