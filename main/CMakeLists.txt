file(GLOB_RECURSE app_sources
  "${CMAKE_SOURCE_DIR}/src/*.c"
  "${CMAKE_SOURCE_DIR}/src/*.cpp")

# Use absolute paths so the files under top-level `src/` are found (they are
# outside the `main/` component directory). idf_component_register accepts
# absolute paths for SRCS.
idf_component_register(SRCS ${app_sources}
                       INCLUDE_DIRS "${CMAKE_SOURCE_DIR}/src"
                                    "${CMAKE_SOURCE_DIR}/libraries"
                                    "${CMAKE_SOURCE_DIR}/libraries/lvgl/src"
                       REQUIRES lvgl esp_lcd driver spi_flash)
