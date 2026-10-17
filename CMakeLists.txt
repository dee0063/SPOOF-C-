cmake_minimum_required(VERSION 3.15)
project(TTY_SPOOFER_DAYZ_CPP VERSION 1.0 LANGUAGES CXX)

# Устанавливаем стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Указываем папку с заголовочными файлами
include_directories(${CMAKE_SOURCE_DIR}/include)

# Исключаем файлы драйвера из сборки (требуют WDK и ntddk.h)
# Собираем только пользовательскую часть (UI + Registry)
add_executable(TTY_SPOOFER
    src/ui/main.cpp
    src/ui/menu.cpp
    src/ui/input.cpp
    src/registry/reg_ops.cpp
)

# Подключаем библиотеку для работы с реестром Windows
target_link_libraries(TTY_SPOOFER PRIVATE advapi32)

# Группировка файлов в Visual Studio по папкам
source_group("UI" FILES 
    src/ui/main.cpp
    src/ui/menu.cpp
    src/ui/input.cpp
)

source_group("Registry" FILES 
    src/registry/reg_ops.cpp
)

# Опционально: если хотите собрать драйвер отдельно (требует WDK)
# add_library(spoof_driver MODULE
#     src/driver/spoof_driver.cpp
#     src/driver/injector.cpp
# )
# target_link_libraries(spoof_driver PRIVATE ntoskrnl.lib)