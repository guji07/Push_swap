cmake_minimum_required(VERSION 3.14)
project(pushswap C)

set(CMAKE_C_STANDARD 11)

add_executable(pushswap Libft/libft.a checker_main.c commands1.c commands2.c push_swap.h push_swap_main.c)

target_link_libraries(pushswap ${CMAKE_SOURCE_DIR}/Libft/libft.a)