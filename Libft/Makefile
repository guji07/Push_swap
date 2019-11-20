SRCS =      flag_char.c         flag_x1.c           ft_isalnum.c        ft_lstdelone.c      ft_memcpy.c         ft_putendl_fd.c     ft_reverse.c        ft_strequ.c         ft_strncat.c        ft_strsub.c         parsers.c \
            flag_f1.c           ft_atoi.c           ft_isalpha.c        ft_lstiter.c        ft_memdel.c         ft_putnbr.c         ft_strcat.c         ft_striter.c        ft_strncmp.c        ft_strtrim.c \
            flag_f2.c           ft_atoidie.c        ft_isascii.c        ft_lstmap.c         ft_memmove.c        ft_putnbr_fd.c      ft_strcatspace.c    ft_striteri.c       ft_strncpy.c        ft_swap.c    \
            flag_int.c          ft_bzero.c          ft_isdigit.c        ft_lstnew.c         ft_memset.c         ft_putnbrpos.c      ft_strchr.c         ft_strjoin.c        ft_strnequ.c        ft_swapint.c \
            flag_o.c            ft_die.c            ft_isprint.c        ft_max.c            ft_pow.c            ft_putnstr.c        ft_strclr.c         ft_strjoinfree.c    ft_strnew.c         ft_tolower.c \
            flag_p.c            ft_flagx2.c         ft_itoa.c           ft_memalloc.c       ft_printf.c         ft_putstr.c         ft_strcmp.c         ft_strlcat.c        ft_strnstr.c        ft_toupper.c \
            flag_percent.c      ft_free_ar.c        ft_itoabase.c       ft_memccpy.c        ft_putchar.c        ft_putstr_fd.c      ft_strcpy.c         ft_strlen.c         ft_strrchr.c        ft_unsignedintlen.c \
            flag_str.c          ft_intlen.c         ft_lstadd.c         ft_memchr.c         ft_putchar_fd.c     ft_putunsignednbr.c ft_strdel.c         ft_strmap.c         ft_strsplit.c       ft_write.c \
            flag_unsignedint.c  ft_intmalloc.c      ft_lstdel.c         ft_memcmp.c         ft_putendl.c        ft_putupstr.c       ft_strdup.c         ft_strmapi.c        ft_strstr.c         get_next_line.c \


OBJECTS	=   flag_char.o         flag_x1.o           ft_isalnum.o        ft_lstdelone.o      ft_memcpy.o         ft_putendl_fd.o     ft_reverse.o        ft_strequ.o         ft_strncat.o        ft_strsub.o         parsers.o \
            flag_f1.o           ft_atoi.o           ft_isalpha.o        ft_lstiter.o        ft_memdel.o         ft_putnbr.o         ft_strcat.o         ft_striter.o        ft_strncmp.o        ft_strtrim.o \
            flag_f2.o           ft_atoidie.o        ft_isascii.o        ft_lstmap.o         ft_memmove.o        ft_putnbr_fd.o      ft_strcatspace.o    ft_striteri.o       ft_strncpy.o        ft_swap.o    \
            flag_int.o          ft_bzero.o          ft_isdigit.o        ft_lstnew.o         ft_memset.o         ft_putnbrpos.o      ft_strchr.o         ft_strjoin.o        ft_strnequ.o        ft_swapint.o \
            flag_o.o            ft_die.o            ft_isprint.o        ft_max.o            ft_pow.o            ft_putnstr.o        ft_strclr.o         ft_strjoinfree.o    ft_strnew.o         ft_tolower.o \
            flag_p.o            ft_flagx2.o         ft_itoa.o           ft_memalloc.o       ft_printf.o         ft_putstr.o         ft_strcmp.o         ft_strlcat.o        ft_strnstr.o        ft_toupper.o \
            flag_percent.o      ft_free_ar.o        ft_itoabase.o       ft_memccpy.o        ft_putchar.o        ft_putstr_fd.o      ft_strcpy.o         ft_strlen.o         ft_strrchr.o        ft_unsignedintlen.o \
            flag_str.o          ft_intlen.o         ft_lstadd.o         ft_memchr.o         ft_putchar_fd.o     ft_putunsignednbr.o ft_strdel.o         ft_strmap.o         ft_strsplit.o       ft_write.o \
            flag_unsignedint.o  ft_intmalloc.o      ft_lstdel.o         ft_memcmp.o         ft_putendl.o        ft_putupstr.o       ft_strdup.o         ft_strmapi.o        ft_strstr.o         get_next_line.o \

HEADER = libft.h
FLAGS = -Wall -Werror -Wextra
NAME = libft.a
all: $(NAME)
$(NAME):$(OBJECTS)
	@ar -rcs $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@echo libft compiled
%.o: %.c $(HEADER)
	@gcc -I . $(FLAGS) $< -c -o $@
clean:
	@rm -f $(OBJECTS)
	@echo .o cleaned
fclean: clean
	@rm -rf $(NAME)
	@echo libft.a cleaned
re: fclean all
.PHONY: clean fclean re
