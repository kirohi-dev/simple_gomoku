#include <system_error>

namespace gomoku {
  enum class future_errc : int {
    invlid_stone_value = 1
  };
  
  class future_cat : public std::error_category {
    public:
      char const* name() const noexcept override;
      std::string message(int ec) const override;
  };
}

namespace std
{
  template <>
  struct is_error_code_enum<gomoku::future_errc> : true_type
  {
  };
}
