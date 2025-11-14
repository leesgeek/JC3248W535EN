cmake_minimum_required(VERSION 3.16.0)

# Build target: this project is for an ESP32-S3 based board (uses GPIO45-48).
# Set `IDF_TARGET` before including ESP-IDF's project helper so the correct
# toolchain and components are selected.
set(IDF_TARGET "esp32s3")

# Ensure LVGL living under `libraries/lvgl` is discovered as an IDF component
# so its sources are built and linked (provides lv_init(), lv_tick_inc(), etc.).
list(APPEND EXTRA_COMPONENT_DIRS "${CMAKE_SOURCE_DIR}/libraries/lvgl")

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(DEMO_LVGL)
