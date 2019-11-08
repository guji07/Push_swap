all:
	@gcc -Wall -Wextra -Werror checker_main.c commands1.c commands2.c -Llibft/ -lft -o checker 
	@echo checker compiled
clean:
	@rm -f checker
	@echo checker delited
re: clean all
