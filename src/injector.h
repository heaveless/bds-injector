#pragma once

#include <filesystem>
#include <fstream>

#include <spdlog/spdlog.h>

#include <pe_bliss/pe_bliss.h>

namespace bds {
  inline std::shared_ptr<spdlog::logger> logger;

  namespace config {
    inline std::filesystem::path bdsExePath;
  }

  namespace data {
    // inline std::unique_ptr<std::deque<>>

    inline struct {
      std::ifstream file;
      std::unique_ptr<pe_bliss::pe_base> pe;
      pe_bliss::export_info exportInfo;
      pe_bliss::exported_functions_list exportedFunctions;
      uint16_t ordinalBase{};
    } originBds;
  }

  void parseArgs(int argc, char** argv);

  int generateModdedBds();
}


