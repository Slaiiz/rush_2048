/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/00/30 11:16:36 by vchesnea          #+#    #+#             */
/*   Updated: 2016/00/30 11:16:36 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

/*
** HACK:
** Line 31: refresh()
** Prevents unwanted screen clearing from future calls to getch()
*/

static int	setup_windows(WINDOW **a, WINDOW **b, WINDOW **c)
{
	static WINDOW	*stdscr;

	if (stdscr)
		wresize(stdscr, LINES, COLS);
	if ((stdscr = initscr()))
	{
		refresh();
		getmaxyx(stdscr, LINES, COLS);
		*a = newwin(WINA_Y, WINA_X, 0, 0);
		wborder(*a, '|', '|', '-', '-', '+', '+', '+', '+');
		*b = newwin(WINB_Y, WINB_X, 0, WINA_X);
		wborder(*b, '|', '|', '-', '-', '+', '+', '+', '+');
		*c = newwin(WINC_Y, WINC_X, WINA_Y, 0);
		wborder(*c, '|', '|', '-', '-', '+', '+', '+', '+');
		wrefresh(*a);
		wrefresh(*b);
		wrefresh(*c);
		raw();
		return (1);
	}
	return (0);
}

int			main(void)
{
	WINDOW	*highscores;
	WINDOW	*gamewindow;
	WINDOW	*score;
	int		key;

	setup_windows(&highscores, &gamewindow, &score);
	while ((key = getch()))
	{
		if (key == KEY_RESIZE)
			setup_windows(&highscores, &gamewindow, &score);
		else if (key == KEY_ESC)
			break ;
	}
	endwin();
	return (0);
}
