/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rludosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 12:24:15 by rludosan          #+#    #+#             */
/*   Updated: 2016/01/31 16:52:20 by rludosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

/*
** Collides the till in the specified direction
** Merges them
** Re-collides
** Add a fresh number in the grid
** Checks if game is still playable
** Return values: (values returned from gameover function)
** 0 : continue
** 1 : win
** 2 : lose
*/

int		move_diff(int **before, int **after)
{
	int	x;
	int	y;

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (before[x][y] != after[x][y])
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}

int		move_left(t_context *gs)
{
	int	**tmp;
	int	x;

	tmp = copy_grid(gs);
	collide_left(gs);
	merge_left(gs);
	collide_left(gs);
	if (move_diff(tmp, gs->grid) == 1)
		add_number(gs);
	x = 0;
	while (x < 16)
		free(tmp[x++]);
	return (gameover(gs));
}

int		move_right(t_context *gs)
{
	int	**tmp;
	int	x;

	tmp = copy_grid(gs);
	collide_right(gs);
	merge_right(gs);
	collide_right(gs);
	if (move_diff(tmp, gs->grid) == 1)
		add_number(gs);
	x = 0;
	while (x < 16)
		free(tmp[x++]);
	return (gameover(gs));
}

int		move_up(t_context *gs)
{
	int	**tmp;
	int	x;

	tmp = copy_grid(gs);
	collide_up(gs);
	merge_up(gs);
	collide_up(gs);
	if (move_diff(tmp, gs->grid) == 1)
		add_number(gs);
	x = 0;
	while (x < 16)
		free(tmp[x++]);
	return (gameover(gs));
}

int		move_down(t_context *gs)
{
	int	**tmp;
	int	x;

	tmp = copy_grid(gs);
	collide_down(gs);
	merge_down(gs);
	collide_down(gs);
	if (move_diff(tmp, gs->grid) == 1)
		add_number(gs);
	x = 0;
	while (x < 16)
		free(tmp[x++]);
	return (gameover(gs));
}
