NAME2 = push_swap
NAME1 = checker
LIBFT = ./libft/libft.a
FILES2 = push_swap_main.c\
		 push_swap2.c    \
		 push_swap3.c	\
		 push_swap4.c	\
		 push_swap5.c	\
		 cases.c

FILES1 = checker_main.c
			
FILES3 = commands1.c	\
		 commands2.c	\
		 commands3.c    \
		 commands4.c

OBJ1 = $(patsubst %.c, %.o, $(FILES1))
OBJ2 = $(patsubst %.c, %.o, $(FILES2))
OBJ3 = $(patsubst %.c, %.o, $(FILES3))
CPPFLAGS	=  -Wall -Werror -Wextra
HEADER		= push_swap.h
NAME 		= $(NAME1) $(NAME2)

all: $(NAME)

$(LIBFT):
	$(MAKE) -sC libft all

$(NAME1): $(OBJ1) $(OBJ3)
	@gcc $(CPPFLAGS) -o $(NAME1) $(OBJ1) $(OBJ3) $(LIBFT)
	@echo checker compiled

$(NAME2): $(OBJ2) $(OBJ3)
	@gcc $(CPPFLAGS) -o $(NAME2) $(OBJ2) $(OBJ3) $(LIBFT)
	@echo push_swap compiled

%.o: %.c $(HEADER) $(LIBFT)
	@gcc -I . $(CPPFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ1) $(OBJ2) $(OBJ3) && $(MAKE) clean -C ./libft

fclean:
	@rm -f $(OBJ1) $(OBJ2) $(OBJ3) && $(MAKE) clean -C ./libft
	@rm -f $(NAME1) $(NAME2) && $(MAKE) fclean -C ./libft

re: fclean all

.PHONY: clean fclean re all
