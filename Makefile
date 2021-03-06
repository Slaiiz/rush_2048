CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
NAME	= game_2048
SRCS	= main.c gui.c game.c\
		  game/add_number.c game/collide.c game/gameover.c game/grid.c game/merge.c game/move.c

help:
	@@echo "\033[33;41mAvailable rules:\033[0m\n\
	\033[30;43mhelp     \033[0m\n\
	\033[30;43mall      \033[0m\n\
	\033[30;43mclean    \033[0m\n\
	\033[30;43mfclean   \033[0m\n\
	\033[30;43mre       \033[0m\n\
	\033[30;43mrenolibft\033[0m\n"

$(NAME):
		make -C libft/;\
		cd srcs;\
		$(CC) $(CFLAGS) -o ../$@ -I ../includes -I ../libft/includes $(SRCS) ../libft/libft.a -lmenu -lncurses;\
		echo "  +%%%%%%%%%=     -%%%%%%%%%#            x%%%-     =%%%%%%%%%+";\
		echo "..x%%%%%%%%%x..  .=%%%%%%%%%#-.        ..#%%%-   ..x%%%%%%%%%x..";\
		echo "##%%x-:--=#%#%= -##%#=--+%#%%#x.       x%#%%%-   =%#%x:--::#%%##";\
		echo "###%=     x##%+ :%##x   -######.     .-#####%-   +%#%=     x%###";\
		echo "####:    .x###= -###x.  -#####x.    .+#######-   =#x#=     +####";\
		echo "x###-     +#x#= -#x#+. .-##xx#x.    -####xxx#-   =#x#=     +#xxx";\
		echo ".-.-.    .+xx#= -xxx+ .xx:+xxx+.   =xxx=-xxxx-   =xxx:     +xxxx";\
		echo "          =xxx= -x+x+ -xx.:xxx+. .-xxxx. +x+x-   :xxx:     =xxxx";\
		echo "         .=x+x= -x+x= -++.:x+++ .+x++:-..+x+x-   :x+x:     +++x+";\
		echo "   .......=+++- .+++= -++.-++++. =+++.   =+++-   -+++=.....=++++";\
		echo "  -+=+=+++++=.. .+++= -+=.-+=+= .=+++.  .=+++-   ..:++++=++++:..";\
		echo "..:+========-   .+=+:..+=.-====. ====.  .====-    .-+=========.";\
		echo "====-........   .===: -== -===:..====.   ====-   -===-.....:====";\
		echo "==:=-           .==::..=: .=:=:. -==:.. .:===..  -===-     :====";\
		echo "-:::-           .:-:- .:- .::-: .-::::::::-::-:. -:-:-     ----:";\
		echo "----.           .:---..-- .-:--. --------------. .:--.     -:--:";\
		echo "----.           .------.  .----     . . .----.   .---.     .----";\
		echo "----.           ..----.   .---..         .---.   .---.     .----";\
		echo ".....           ....-..   .....         ......   .....     .-...";\
		echo "......          ........  .....          .....   ..... .  ......";\
		echo "...............    ...........           ....       ..........";\
		echo "..   . . .. .       .  . .. .               .       . . .  ."

all: $(NAME)

clean:
		make -C libft/ clean;\
		cd srcs;\
		rm -f $(subst .c,.o,$(SRCS))

fclean: clean
		make -C libft/ fclean;\
		rm -f $(NAME)

re: fclean all

renolibft:
		rm -f $(NAME);\
		make game_2048

.PHONY: all clean fclean re
