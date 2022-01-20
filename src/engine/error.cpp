#include <system_error>
#include "error.hpp"

namespace std {
  template <>
  struct is_error_code_enum<gomoku::FutureErrc> : true_type {};
}

class future_cat : public std::error_category {
  public:
    char const* name() const noexcept override {
      return "future";
    }

    std::string message(int ec) const override {
        switch (static_cast<gomoku::FutureErrc>(ec))
        {
        case gomoku::FutureErrc::invlid_stone_value:
          return "future_error: invlid_stone_value";
        default:
          return "bad futurecat code";
         }
    }
};

std::error_category const& future_category() noexcept {
  static future_cat obj;
  return obj;
}

std::error_code gomoku::make_error_code(gomoku::FutureErrc e) noexcept
{
  return std::error_code{static_cast<int>(e), future_category()};
}
