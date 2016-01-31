/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameover.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rludosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 12:18:51 by rludosan          #+#    #+#             */
/*   Updated: 2016/01/31 14:18:32 by rludosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

/*
 * Checks if a till is mergable
 * Return values:
 * 0 : till cannot merge
 * 1 : till can merge
 */

static int	till_touch(t_context *gs, int x, int y)
{
	int		touch;

	touch = 0;
	if (y != 0 && gs->grid[x][y] == gs->grid[x][y - 1])
		touch++;
	if ((y != 3) && gs->grid[x][y] == gs->grid[x][y + 1])
		touch++;
	if ((x != 0) && gs->grid[x][y] == gs->grid[x - 1][y])
		touch++;
	if ((x != 3) && gs->grid[x][y] == gs->grid[x + 1][y])
		touch++;
	if (touch == 0)
		return (0);
	return (1);
}

/*
 * Return values:
 * 0 : continue
 * 1 : win
 * 2 : lose
 */

int			gameover(t_context *gs)
{
	int		x;
	int		y;
	int		err;

	err = 0;
	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (gs->grid[x][y] == WIN_VALUE)
				return (1);
			if (till_touch(gs, x, y) == 0)
				err++;
			y++;
		}
		x++;
	}
	err = (err == 16) ? 2 : 0;
	return (err);
}
