#pragma once

#include <filesystem>
#include <optional>
#include <string_view>

namespace bds::ChooseFileUtil {
  std::optional<std::filesystem::path> chooseFile(const wchat_t* title, const wchat_t* filter);
}
