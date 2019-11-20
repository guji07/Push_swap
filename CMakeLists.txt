Cmake_minimum_required(VERSION 3.14)
project(pushswap C)

set(CMAKE_C_STANDARD 11)

add_executable(pushswap Libft/libft.a push_swap_main.c push_swap2.c push_swap3.c push_swap4.c push_Swap5.c commands1.c commands2.c commands3.c commands4.c push_swap.h Libft/ft_free_ar.c)
add_executable(checker Libft/libft.a checker_main.c commands1.c commands2.c commands3.c commands4.c push_swap.h Libft/ft_atoidie.c)

target_link_libraries(checker ${CMAKE_SOURCE_DIR}/Libft/libft.a)
target_link_libraries(pushswap ${CMAKE_SOURCE_DIR}/Libft/libft.a)
