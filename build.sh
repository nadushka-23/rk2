#!/bin/bash
set -e

<<<<<<< HEAD
rm -rf build 
mkdir build 
cd build
cmake ..
cmake --build . --parallel $(nproc)
ctest --output-on-failure
cpack
=======
# Очистка и создание директории сборки
rm -rf build && mkdir build && cd build

# Конфигурация с включенными тестами
cmake -DBUILD_TESTS=ON ..

# Сборка
cmake --build . --parallel $(nproc)

# Запуск тестов через CTest (более надежный способ)
ctest --output-on-failure
>>>>>>> dcf5e13 (fix: final build and test configuration)
