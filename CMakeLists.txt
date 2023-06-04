cmake_minimum_required(VERSION 3.11)

project(functions CXX)

set(CMAKE_CXX_STANDARD 23)

# Специфичные настройки для компилятора Visual Studio
if(MSVC)
    # Генерируем статическую заглушку для динамических библиотек
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS true)

    # Включаем высокий уровень предупреждений
    if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif()
endif()

# Объявляем библиотеку
add_library(sequence SHARED "include/sequence/sequence.h" "src/sequence.cc" "src/container.cc")
target_include_directories(sequence PUBLIC "include")

# Подключаем googletest
include(FetchContent)
FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/6b63c98ac43efc992122f1da12aaf0a0e0658206.zip)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Объявляем тесты
add_executable(sequences_tests "tests/sequences_tests.cc")
target_link_libraries(sequences_tests sequence GTest::gtest_main)

# Объявляем консоль
add_executable(console "src/console.cc")
target_link_libraries(console sequence)