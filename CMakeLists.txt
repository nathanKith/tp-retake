cmake_minimum_required(VERSION 3.13.4)
project(reexam)

set(CMAKE_CXX_STANDARD 14)

SET(CMAKE_CXX_FLAGS -pthread)

include_directories(include tests/include)

add_executable(reexam main.cpp src/Date.cpp src/Letter.cpp include/LetterList.h src/LetterList.cpp tests/src/tests.cpp tests/src/tests.cpp)

target_link_libraries(reexam -lgcov -fprofile-arcs -ftest-coverage -fPIC)
target_compile_options(reexam PUBLIC --coverage PUBLIC -lgcov PUBLIC -fprofile-arcs PUBLIC -ftest-coverage PUBLIC -fPIC)