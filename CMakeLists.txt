cmake_minimum_required(VERSION 3.23)
project(TP5_ACPM C)

set(CMAKE_C_STANDARD 99)

add_executable(TP5_ACPM main.c graphe.h prim/prim.h Kruskal/kruskal.h Kruskal/kruskal.c graphe.c prim/prim.c)
