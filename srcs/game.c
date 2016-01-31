/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/00/30 11:16:36 by vchesnea          #+#    #+#             */
/*   Updated: 2016/00/30 11:16:36 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

/*
** Update the score window with the new amount of points.
** @param WINDOW *c				- The concerned window handle
** @param int points			- Number to be displayed
*/

void	update_score(WINDOW *c, int points)
{
	char	*s;

	s = "Points:";
	mvwaddstr(c, CENTER(WINC_Y, 1), 2, s);
	s = ft_itoa(points);
	mvwaddstr(c, CENTER(WINC_Y, 1), WINC_X - ft_strlen(s) - 2, s);
	wrefresh(c);
	free(s);
}

/*
** Feed the game a keystroke and let it run one cycle.
** @param t_context gamestate	- A structure containing the state of the game.
** @param int key				- A keystroke
*/

void	step_game(t_context *gamestate, int key)
{
	if (!gamestate->is_running)
	{
		if (key == KEY_ENTER)
		{
			gamestate->is_running = 1;
		}
	}
}
