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

void	setup_text(WINDOW *a, WINDOW *b, WINDOW *c)
{
	int		repeat;
	char	*s;

	s = "~ 2048 ~";
	mvwaddstr(a, 2, CENTER(WINA_X, ft_strlen(s)), s);
	repeat = WINA_X - 2;
	wmove(a, 4, 1);
	while (repeat--)
		waddch(a, '=');
	s = "highscores";
	mvwaddstr(a, 6, CENTER(WINA_X, ft_strlen(s)), s);
	update_score(c, 0);
	return ;
}

/*
** HACK:
** Line 46: refresh()
** Prevents unwanted screen clearing from future calls to getch()
*/

int		setup_windows(WINDOW **a, WINDOW **b, WINDOW **c)
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
		setup_text(*a, *b, *c);
		wrefresh(*a);
		wrefresh(*b);
		wrefresh(*c);
		raw();
		return (1);
	}
	return (0);
}
