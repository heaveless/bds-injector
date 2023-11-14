add_rules("mode.debug", "mode.release")

set_policy("package.requires_lock", true)
-- add_repositories("local-repo repository")
add_repositories("xmake-repo https://github.com/heaveless/xmake-repo.git")

add_requires("fmt")
add_requires("spdlog")

add_requires("cxxopts")
add_requires("pe_bliss")

target("bds-injector")
  set_kind("binary")
  add_files("src/*.cpp")
  add_defines("UNICODE", "BDS_INJECTOR_VERSION=\"v1.0.0\"")
  add_packages("fmt", "spdlog", "pe_bliss", "cxxopts")
