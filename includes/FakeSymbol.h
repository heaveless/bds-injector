#pragma once

#include <optional>
#include <string>

namespace bds::FakeSymbol {
  std::optional<std::string> getFakeSymbol(const std::string& fn, bool removeVirtual = false);
}
