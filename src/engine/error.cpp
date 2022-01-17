#include <system_error>
#include "error.hpp"

namespace std {
  template <>
  struct is_error_code_enum<gomoku::future_errc> : true_type {};
}
