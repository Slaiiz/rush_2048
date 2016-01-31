/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 11:16:36 by vchesnea          #+#    #+#             */
/*   Updated: 2016/01/31 16:42:24 by rludosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static int	get_input(t_context *gamestate, int key)
{
	int		condition;

	if (key == KEY_LEFT)
		condition = move_left(gamestate);
	else if (key == KEY_UP)
		condition = move_up(gamestate);
	else if (key == KEY_RIGHT)
		condition = move_right(gamestate);
	else if (key == KEY_DOWN)
		condition = move_down(gamestate);
	else
		return (-1);
	return (condition);
}

/*
** Update the score window with the new amount of points.
** @param t_context *gamestate	- The current state of the game
*/

void		update_score(t_context *gamestate)
{
	WINDOW	*window;
	char	*s;

	window = gamestate->windows[SCORE];
	s = "Points:";
	mvwaddstr(window, CENTER(WINC_Y, 1), 2, s);
	s = ft_itoa(gamestate->points);
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
			update_score(gamestate);
			new_grid(gamestate);
			draw_grid(gamestate);
		}
	}
	else
	{
		if ((condition = get_input(gamestate, key)) != -1)
		{
			update_grid(gamestate);
			if (condition != 0)
				gamestate->is_running = 0;
		}
	}
}
