/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addnum.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rludosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 12:12:30 by rludosan          #+#    #+#             */
/*   Updated: 2016/01/31 16:39:10 by rludosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

/*
** Add a fresh 2 or 4 in the grid if space is available
*/

static int		numrand(void)
{
	int			x;

	x = rand() % ((100 - 1) + 1);
	if (x > 50)
		return (2);
	return (4);
}

void			addnum(t_context *gs)
{
	int			x;
	int			y;

	x = rand() % 3;
	y = rand() % 3;
	while (gs->grid[x][y] != 0)
	{
		x = rand() % 3;
		y = rand() % 3;
	}
	gs->grid[x][y] = numrand();
}
