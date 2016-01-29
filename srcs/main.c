#include <unistd.h>
#include <curses.h>
#include <stdio.h>

static void	fillscreen(char c)
{
	int	position;

	position = COLS * LINES;
	while (position--)
		mvaddch(position / COLS, position % COLS, c | COLOR_PAIR(0));
	return ;
}

int			main(void)
{
	initscr();
	start_color();
	fillscreen('@');
	refresh();
	sleep(1);
	endwin();
	return (0);
}
