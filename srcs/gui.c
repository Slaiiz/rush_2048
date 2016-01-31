/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/00/30 11:16:36 by vchesnea          #+#    #+#             */
/*   Updated: 2016/00/30 11:16:36 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

/*
** Draw or update the game grid.
** First iterate over the x axis, then the y axis.
** Give up if the maximum size of a square isn't enough to fit in a digit.
** @param WINDOW *c			- The concerned window handle
*/

void	draw_grid(WINDOW *c)
{
	int		size_x;
	int		size_y;
	int		i;

	size_x = WINB_X / 4;
	size_y = WINB_Y / 4;
	if (size_x < 1 || size_x < 1)
		return ;
	i = 4;
	while (i--)
		mvwvline(c, 1, size_x * i + 1, '#', WINB_Y - 2);
	i = 4;
	while (i--)
		mvwhline(c, size_y * i + 1, 1, '#', WINB_X - 2);
	wrefresh(c);
}

/*
** Write all the fancy text on your surfaces.
** @param WINDOW **windows	- An array of windows
*/

void	setup_text(WINDOW **windows)
{
	WINDOW	*window;
	int		repeat;
	char	*s;

	window = windows[HIGHSCORES];
	s = "~ 2048 ~";
	mvwaddstr(window, 2, CENTER(WINA_X, ft_strlen(s)), s);
	repeat = WINA_X - 2;
	wmove(window, 4, 1);
	while (repeat--)
		waddch(window, '=');
	s = "highscores";
	mvwaddstr(window, 6, CENTER(WINA_X, ft_strlen(s)), s);
	s = "Press ENTER to start the game";
	mvwaddstr(window, WINA_Y - 2, CENTER(WINA_X, ft_strlen(s)), s);
	update_score(windows[SCORE], 0);
	wnoutrefresh(window);
	wnoutrefresh(windows[GAMEWINDOW]);
	wnoutrefresh(windows[SCORE]);
	doupdate();
}

/*
** Draw each window in a way that will cover the entire screen.
** Can be recalled further on for updating.
** @param WINDOW **windows	- An array of windows
** HACK:
** Line 56: refresh()
** Prevents unwanted screen clearing from future calls to getch()
*/

int		setup_windows(WINDOW **windows)
{
	WINDOW	*window;

	if ((windows[STDSCR] = initscr()))
	{
		refresh();
		getmaxyx(windows[STDSCR], LINES, COLS);
		window = newwin(WINA_Y, WINA_X, 0, 0);
		wborder(window, '|', '|', '-', '-', '+', '+', '+', '+');
		windows[HIGHSCORES] = window;
		window = newwin(WINB_Y, WINB_X, 0, WINA_X);
		wborder(window, '|', '|', '-', '-', '+', '+', '+', '+');
		windows[GAMEWINDOW] = window;
		window = newwin(WINC_Y, WINC_X, WINA_Y, 0);
		wborder(window, '|', '|', '-', '-', '+', '+', '+', '+');
		windows[SCORE] = window;
		setup_text(windows);
		keypad(windows[STDSCR], 1);
		cbreak();
		noecho();
		curs_set(0);
		draw_grid(windows[GAMEWINDOW]);
		return (1);
	}
	return (0);
}
