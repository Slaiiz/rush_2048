CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
NAME	= game_2048
SRCS	= main.c

all: $(NAME)

$(NAME):
		cd srcs;\
		$(CC) $(CFLAGS) -o ../$@ -I ../includes $(SRCS) -lncurses

clean:
		cd srcs;\
		rm -f $(subst .c,.o,$(SRCS))

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
