CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
NAME	= game_2048
SRCS	= main.c gui.c game.c

help:
	@echo "\033[33;41mAvailable rules:\033[0m\n\
	\033[30;43mhelp     \033[0m\n\
	\033[30;43mall      \033[0m\n\
	\033[30;43mclean    \033[0m\n\
	\033[30;43mfclean   \033[0m\n\
	\033[30;43mre       \033[0m\n\
	\033[30;43mrenolibft\033[0m\n"

$(NAME):
		cd srcs;\
		make -C libft/;\
		$(CC) $(CFLAGS) -o ../$@ -I ../includes -I libft/includes $(SRCS) libft/libft.a -lmenu -lncurses

all: $(NAME)

clean:
		cd srcs;\
		make -C libft/ clean;\
		rm -f $(subst .c,.o,$(SRCS))

fclean: clean
		make -C srcs/libft/ fclean;\
		rm -f $(NAME)

re: fclean all

renolibft:
		rm -f $(NAME);\
		make game_2048

.PHONY: all clean fclean re
