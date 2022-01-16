#include <pybind11/pybind11.h>
#include "gomoku.hpp"

PYBIND11_MODULE(gomoku_engine, m)
{
  m.doc() = "engine module";
  m.def("add", &add, "add two numbers");
}
