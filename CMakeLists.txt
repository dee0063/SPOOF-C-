# CMakeLists.txt — сборка UI-слоя и драйвера под MSVC (Visual Studio 2019/2022)
cmake_minimum_required(VERSION 3.15)
project(TTY_SPOOFER_DAYZ_CPP LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# UI-слой (консольное приложение)
add_executable(tty-spoof dayz_ui_main.cpp dayz_ui_menu.cpp dayz_ui_input.cpp)

# Драйверный слой (.sys)
add_library(spoof_driver STATIC spoof_driver.cpp injector.cpp reg_ops.cpp)
target_include_directories(spoof_driver PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Сборка .sys (MSVC)
add_custom_command(TARGET spoof_driver POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:spoof_driver>
        ${CMAKE_BINARY_DIR}/spoof_driver.sys
    COMMENT "Copying driver to output folder")

# Инъектор (загрузка драйвера в ядро)
add_executable(injector injector.cpp)
target_include_directories(injector PRIVATE ${CMAKE_SOURCE_DIR}/include)
