cmake_minimum_required(VERSION 3.10)
project(ChainOfResponsibility VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)

# Основная программа
add_executable(worker_app src/worker.cpp)

# Тесты
enable_testing()
add_executable(check_tests tests/test_chain.cpp src/worker.cpp)
target_compile_definitions(check_tests PRIVATE RUNNING_TESTS)
add_test(NAME RunTests COMMAND check_tests)

# Установка
install(TARGETS worker_app DESTINATION bin)

# Настройки CPack
set(CPACK_GENERATOR "DEB")
set(CPACK_PACKAGE_NAME "chain-worker")
set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION}")
set(CPACK_PACKAGE_CONTACT "nadushka-23 <github@nadushka>")
set(CPACK_PACKAGE_DESCRIPTION "RK2 Chain Package")

# ИКЛЮЧАЕМ ТОЛЬКО В КОНЦЕ
include(CPack)
