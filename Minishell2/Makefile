##
## EPITECH PROJECT, 2023
## B-PSU-200-LYN-2-1-minishell1-elias.abassi
## File description:
## Makefile
##

SRC_LIB	=	-L./lib/my -lmy

SRC	=	main.c	\
		cpy_env.c	\
		prompt.c	\
		exit.c	\
		check_input.c	\
		my_str_to_word_array.c	\
		directory_path.c	\
		do_binary.c	\
		errors.c	\
		env.c	\
		setenv.c	\
		unsetenv.c	\
		free.c

OBJ	=	$(SRC:.c=.o)

NAME	=	 mysh

CFLAGS = -Wall -Wextra -W -g3

all:	$(NAME)

$(NAME): $(OBJ)
		make -C lib/my
		make clean -C lib/my
		cd ../..
		gcc $(OBJ) -o $(NAME) -I./include $(SRC_LIB) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm lib/my/libmy.a

re: fclean all

.PHONY	:	all clean fclean re
