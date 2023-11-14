#include "injector.h"

#include <iostream>
#include <locale>

#include <fmt/core.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <cxxopts/cxxopts.hpp>

#include "cxxopts-adder.h"

namespace bds {
  void parseArgs(int argc, char** argv) {
    using cxxopts::value;
    using std::string;

    cxxopts::Options options("bdsinj", "bds ToolChain bds-injector " BDS_INJECTOR_VERSION);
    options.allow_unrecognised_options();
    options.set_width(-1);

    CxxOptsAdder(options)
      .add(
          "m,mod",
          "Generate modded bds",
          value<bool>()->default_value("false")
      )
      .add(
          "b,bak",
          "Generate backup bds",
          value<bool>()->default_value("false")
      )
      .add(
          "h,help",
          "Show help"
      );

    auto optionsResult = options.parse(argc, argv);
  }

  int generateModdedBds() {
    using namespace data;
    using namespace pe_bliss;

    logger->info("Loading BDS executable file...");
    originBds.file.open(config::bdsExePath, std::ios::in | std::ios::binary);

    if (!data::originBds.file) {
      logger->error("Failed to open BDS executable file.");
      return -1;
    }
  } 
}

int main(int argc, char** argv) {
  using namespace bds;
   
  spdlog::set_pattern("[%H:%M:%S.%e] [%^%l%$] %v");
  logger = spdlog::stdout_color_mt("console");
  logger->set_level(spdlog::level::info);

  std::locale::global(std::locale("en_US.UTF-8"));
  
  logger->info("Hello, World! with logger");
  

  fmt::print("Hello, World!\n");
  return 0;
}
