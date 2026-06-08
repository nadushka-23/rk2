cmake_minimum_required(VERSION 3.10)
project(ChainOfResponsibility VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)

# Наша основная программа
add_executable(worker_app src/worker.cpp)

# Включаем тесты
enable_testing()
add_executable(check_tests tests/test_chain.cpp)
add_test(NAME RunTests COMMAND check_tests)

# Куда ставить готовую программу для создания DEB-пакета
install(TARGETS worker_app DESTINATION bin)

# Настройки для создания .deb пакета для релиза
set(CPACK_GENERATOR "DEB")
set(CPACK_PACKAGE_NAME "chain-worker")
set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION}")
set(CPACK_PACKAGE_CONTACT "nadushka-23 <github@nadushka>")
set(CPACK_PACKAGE_DESCRIPTION "RK2 Chain Package")
include(CPack)
