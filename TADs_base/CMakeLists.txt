cmake_minimum_required(VERSION 4.4)
project(TADs_base)

set(CMAKE_CXX_STANDARD 20)

add_executable(TADs_base main.cpp
        Biblioteca/Nodo.h
        Biblioteca/Lista.h)
