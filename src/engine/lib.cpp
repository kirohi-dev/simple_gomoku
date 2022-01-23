#include <pybind11/pybind11.h>
#include <system_error>
#include "gomoku.hpp"
#include "error.hpp"

void error_test()
{
  std::error_code ec = gomoku::make_error_code(gomoku::FutureErrc::invlid_stone_value);
  throw std::system_error(ec, "system error");
}

PYBIND11_MODULE(gomoku_engine, m)
{
  m.doc() = "engine module";
  m.def("error_test", &error_test, "test error");
}
