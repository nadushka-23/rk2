# Включаем тесты
enable_testing()

# Создаем исполняемый файл теста, включая туда и сам исходник класса
add_executable(check_tests tests/test_chain.cpp src/worker.cpp)

# Добавляем определение макроса, чтобы код внутри #ifndef RUNNING_TESTS сработал
target_compile_definitions(check_tests PRIVATE RUNNING_TESTS)

# Регистрируем тест в ctest
add_test(NAME RunTests COMMAND check_tests)
