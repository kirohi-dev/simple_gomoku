#ifndef GOMOKU_ERROR_H
#define GOMOKU_ERROR_H

#include <system_error>

namespace gomoku {
  enum class future_errc : int {
    invlid_stone_value = 1
  };
  
  // class future_cat : public std::error_category {
  //   public:
  //     char const* name() const noexcept override;
  //     std::string message(int ec) const override;
  // };
  
  // std::error_category const& future_category() noexcept;
  std::error_code make_error_code(future_errc e) noexcept;
}

// namespace std
// {
//   template <>
//   struct is_error_code_enum<gomoku::future_errc> : true_type{};
// }

#endif // GOMOKU_ERROR_H
