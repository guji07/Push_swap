all:
		@gcc -Wall -Wextra -Werror checker_main.c commands1.c commands2.c  -Llibft -lft -o checker
		@echo checker compiled
		@gcc -Wall -Wextra -Werror push_swap_main.c commands1.c commands2.c  -Llibft/ -lft -o push_swap
		@echo push_swap compiled
clean:
		@rm -f checker
		@rm -f push_swap
		@echo checker and push_swap delited
re: clean all
