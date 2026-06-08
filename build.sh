#!/bin/bash
set -e

mkdir -p build && cd build
cmake ..
# -j$(nproc) — это и есть параллельная сборка на всех ядрах!
cmake --build . -- -j$(nproc)
# Запуск тестов
ctest --output-on-failure
# Сборка .deb пакета
cpack
