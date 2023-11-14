#pragma once

#include <string>
#include <vector>

#include "ctre.hpp"

namespace bds::Filter {
  const std::vector<std::string> prefix = {
    "_",
    "?__",
    "??_",
    "??@",
    "?$TSS",
    "??_C"
  };

  inline bool matchSkip(std::string_view name) {
    return ctre::match<R"(\?+[a-zA-Z0-9_\-]*([a-zA-Z0-9_\-]*@)*std@@.*)">(name) || ctre::match<R"(.*printf$)">(name) || ctre::match<R"(.*no_alloc.*)">(name);
  }
}
