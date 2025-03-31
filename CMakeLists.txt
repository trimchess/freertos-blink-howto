cmake_minimum_required(VERSION 3.20)

# General project definitions
set(OUTPUT_NAME APP)
set(PROJECT_NAME ${OUTPUT_NAME})
set(PICO_BOARD pico2)

# SDK definitions
set(PICO_SDK_PATH $ENV{PICO_SDK_PATH})
set(PICO_SDK_ROOT $ENV{PICO_SDK_ROOT_PATH})

# Toolchain definitions
set(PICO_TOOLCHAIN_PATH $ENV{PICO_ARM_TOOLCHAIN_PATH})

# Pull in SDK from the SDK
include(${PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(${PROJECT_NAME} C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(PICO_CXX_ENABLE_EXCEPTIONS 1)	

# initialize SDK
pico_sdk_init()

# FreeRTOS definitions and pull in FreeRTOS
SET(FREERTOS_CONFIG_FILE_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/local-config/FreeRTOS-Kernel" CACHE STRING "Local Config")
include(FreeRTOS_Kernel_import.cmake)

# Output some variables
include(CMakePrintHelpers)
cmake_print_variables(CMAKE_C_STANDARD)
cmake_print_variables(CMAKE_CXX_STANDARD)
cmake_print_variables(PICO_BOARD)
cmake_print_variables(PICO_PLATFORM)
cmake_print_variables(PICO_SDK_PATH)
cmake_print_variables(PICO_SDK_VERSION_STRING)
cmake_print_variables(PICO_TOOLCHAIN_PATH)
cmake_print_variables(PICO_COMPILER)
cmake_print_variables(CMAKE_C_COMPILER_ID)

# include src directory
add_subdirectory(src)

