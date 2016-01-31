/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 11:16:36 by vchesnea          #+#    #+#             */
/*   Updated: 2016/01/31 14:39:58 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

/*
** Fill a slot in the grid contained in the given window with a number.
** The color of that slot will change in consequence.
** @param WINDOW *c				- The concerned window handle
** @param int slot				- A number designating a slot, 0 <= x < 16
** @param int number			- The number to write in the given slot
*/

void	fill_slot(WINDOW *c, int slot, int number)
{
	int		pos_x;
	int		pos_y;
	char	*s;

	pos_y = WINB_Y / 4 * (slot / 4) + WINB_Y / 8;
	pos_x = WINB_X / 4 * (slot % 4) + WINB_X / 8;
	if (number != 0)
	{
		s = ft_itoa(number);
		mvwaddstr(c, pos_y, pos_x - ft_strlen(s) / 2, s);
		free(s);
	}
	else
		mvwhline(c, pos_y, pos_x - WINB_X / 8 + 2, ' ', WINB_X / 4 - 1);
}

/*
** Fits in game data onto the game window;
** @param t_context *gamestate	- Figure it out yourself
*/

void		update_grid(t_context *gamestate)
{
	WINDOW	*window;
	int		**grid;
	int		x;
	int		y;

	window = gamestate->windows[GAMEWINDOW];
	grid = gamestate->grid;
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 0)
		{
			fill_slot(window, y * 4 + x, grid[y][x]);
			x++;
		}
		y++;
	}
	wrefresh(window);
	return ;
}

/*
** Draw or update the game's 4x4 grid.
** First iterate over the x axis, then the y axis.
** Give up if the maximum size of a square isn't enough to fit in a digit.
** @param t_context *gamestate	- The current state of the game
*/

void		draw_grid(t_context *gamestate)
{
	WINDOW	*window;
	int		size_x;
	int		size_y;
	int		i;

	window = gamestate->windows[GAMEWINDOW];
	size_x = WINB_X / 4;
	size_y = WINB_Y / 4;
	if (size_x < 1 || size_x < 1)
		return ;
	i = 4;
	while (i--)
		mvwvline(window, 1, size_x * i + 1, '#', WINB_Y - 2);
	i = 4;
	while (i--)
		mvwhline(window, size_y * i + 1, 1, '#', WINB_X - 2);
	update_grid(gamestate);
	wrefresh(window);
}

/*
** Write all the fancy text on your surfaces.
** @param t_context *gamestate	- The current state of the game
*/

static void	setup_text(t_context *gamestate)
{
	WINDOW	*window;
	int		repeat;
	char	*s;

	window = gamestate->windows[HIGHSCORES];
	s = "~ 2048 ~";
	mvwaddstr(window, 2, CENTER(WINA_X, ft_strlen(s)), s);
	repeat = WINA_X - 2;
	wmove(window, 4, 1);
	while (repeat--)
		waddch(window, '=');
	s = "highscores:";
	mvwaddstr(window, 6, CENTER(WINA_X, ft_strlen(s)), s);
	if (!gamestate->is_running)
	{
		s = "Press ENTER to start the game";
		mvwaddstr(window, WINA_Y - 2, CENTER(WINA_X, ft_strlen(s)), s);
	}
	wnoutrefresh(window);
	wnoutrefresh(gamestate->windows[GAMEWINDOW]);
	wnoutrefresh(gamestate->windows[SCORE]);
	doupdate();
}

/*
** Draw each window in a way that will cover the entire screen.
** Can be recalled further on for updating.
** @param t_context *gamestate	- The current state of the game
** HACK: refresh()
** Prevents unwanted screen clearing from future calls to getch()
*/

int			setup_windows(t_context *gamestate)
{
	WINDOW	*window;

	if ((gamestate->windows[STDSCR] = initscr()))
	{
		refresh();
		getmaxyx(gamestate->windows[STDSCR], LINES, COLS);
		window = newwin(WINA_Y, WINA_X, 0, 0);
		wborder(window, '|', '|', '-', '-', '+', '+', '+', '+');
		gamestate->windows[HIGHSCORES] = window;
		window = newwin(WINB_Y, WINB_X, 0, WINA_X);
		wborder(window, '|', '|', '-', '-', '+', '+', '+', '+');
		gamestate->windows[GAMEWINDOW] = window;
		window = newwin(WINC_Y, WINC_X, WINA_Y, 0);
		wborder(window, '|', '|', '-', '-', '+', '+', '+', '+');
		gamestate->windows[SCORE] = window;
		setup_text(gamestate);
		keypad(gamestate->windows[STDSCR], 1);
		cbreak();
		noecho();
		curs_set(0);
		return (1);
	}
	return (0);
}
