/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 11:16:36 by vchesnea          #+#    #+#             */
/*   Updated: 2016/01/31 14:40:09 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void	update_grid(t_context *gamestate)
{

}

static void	get_input (t_context *gamestate, int key)
{
	if (key == KEY_LEFT)
		condition = move_left();
	else if (key == KEY_UP)
		condition = move_up();
	else if (key == KEY_RIGHT)
		condition = move_right();
	else if (key == KEY_DOWN)
		condition = move_down();
	else
		return (0);
	return (1);
}

/*
** Update the score window with the new amount of points.
** @param WINDOW *c				- The concerned window handle
** @param int points			- Number to be displayed
*/

static void	update_score(t_context *gamestate, int points)
{
	WINDOW	*window;
	char	*s;

	window = gamestate->windows[SCORE];
	s = "Points:";
	mvwaddstr(window, CENTER(WINC_Y, 1), 2, s);
	s = ft_itoa(points);
	mvwaddstr(window, CENTER(WINC_Y, 1), WINC_X - ft_strlen(s) - 2, s);
	wrefresh(window);
	free(s);
}

/*
** Feed the game a keystroke and let it run one cycle.
** @param t_context gamestate	- A structure containing the state of the game.
** @param int key				- A keystroke
*/

void		step_game(t_context *gamestate, int key)
{
	WINDOW	**windows;
	int		condition;

	windows = gamestate->windows;
	if (!gamestate->is_running)
	{
		if (key == KEY_RETURN)
		{
			gamestate->is_running = 1;
			mvwhline(windows[HIGHSCORES], WINA_Y - 2, 1, ' ', WINA_X - 2);
			wrefresh(windows[HIGHSCORES]);
			update_score(gamestate, 0);
			draw_grid(gamestate);
			gamestate->grid = new_grid();
			addnum(gamestate);
			addnum(gamestate);
		}
	}
	else
	{
		if (get_input(gamestate, key))
		{
			update_grid(gamestate)
			if (conditon != 0)
				gamestate->is_running = 0;
		}
	}
}
