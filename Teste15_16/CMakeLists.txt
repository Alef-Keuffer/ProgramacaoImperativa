cmake_minimum_required(VERSION 3.19)
project(Teste15_16 C)

add_library(Teste15_16 Teste15_16.c Teste15_16.h tests.c tests.h)
add_executable(main main.c)
target_link_libraries(main Teste15_16)