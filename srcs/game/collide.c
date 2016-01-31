/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collide.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rludosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 12:07:41 by rludosan          #+#    #+#             */
/*   Updated: 2016/01/31 14:25:05 by rludosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

/*
 * All the collide functions slide the tills to one edge
 * Notes: It does not merge them, check sum functions for that
 */

void	collide_left(t_context *gs)
{
	int	x;
	int	y;
	int	z;
	int	val;

	x = 0;
	while (x < 4)
	{
		y = 1;
		while (y < 4)
		{
			if (gs->grid[x][y] != 0)
			{
				val = gs->grid[x][y];
				gs->grid[x][y] = 0;
				z = y;
				while (gs->grid[x][z] == 0 && z >= 0)
					z--;
				gs->grid[x][z + 1] = val;
			}
			y++;
		}
		x++;
	}
}

void	collide_right(t_context *gs)
{
	int	x;
	int	y;
	int	z;
	int	val;

	x = 0;
	while (x < 4)
	{
		y = 3;
		while (y >= 0)
		{
			if (gs->grid[x][y] != 0)
			{
				val = gs->grid[x][y];
				gs->grid[x][y] = 0;
				z = y;
				while (gs->grid[x][z] == 0 && z < 4)
					z++;
				gs->grid[x][z - 1] = val;
			}
			y--;
		}
		x++;
	}
}

void	collide_up(t_context *gs)
{
	int	x;
	int	y;
	int	z;
	int	val;

	x = 1;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (gs->grid[x][y] != 0)
			{
				val = gs->grid[x][y];
				gs->grid[x][y] = 0;
				z = x;
				while (gs->grid[z][y] == 0 && z > 0)
					z--;
				z = (gs->grid[z][y] != 0) ? z + 1 : z;
				gs->grid[z][y] = val;
			}
			y++;
		}
		x++;
	}
}

void	collide_down(t_context *gs)
{
	int	x;
	int	y;
	int	z;
	int	val;

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (gs->grid[x][y] != 0)
			{
				val = gs->grid[x][y];
				gs->grid[x][y] = 0;
				z = x;
				while (gs->grid[z][y] == 0 && z < 4)
					z++;
				gs->grid[z - 1][y] = val;
			}
			y++;
		}
		x++;
	}
}
