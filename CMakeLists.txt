cmake_minimum_required(VERSION 3.19)
project(ProgramacaoImperativa C)
add_subdirectory(Teste15_16)

set(CMAKE_C_STANDARD 11)

add_library(ProgramacaoImperativa library.c library.h)