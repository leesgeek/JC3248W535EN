# This file was automatically generated for projects
# without default 'CMakeLists.txt' file.

FILE(GLOB_RECURSE app_sources ${CMAKE_SOURCE_DIR}/src/*.*)

# Ensure headers in `src/` (for example `lv_conf.h`) are added to include path
idf_component_register(SRCS ${app_sources}
					   INCLUDE_DIRS ".")
