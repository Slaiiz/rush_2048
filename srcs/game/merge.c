/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rludosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 12:07:57 by rludosan          #+#    #+#             */
/*   Updated: 2016/01/31 16:41:30 by rludosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

/*
** Merge functions, merge the tills with the same number
** Notes: Must be followed by a collide function to replace
** the tills at the edge
*/

void	merge_left(t_context *gs)
{
	int	x;
	int	y;

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 3)
		{
			if (gs->grid[x][y] != 0 && gs->grid[x][y] == gs->grid[x][y + 1])
			{
				gs->grid[x][y] += gs->grid[x][y + 1];
				gs->points += gs->grid[x][y + 1];
				gs->grid[x][y + 1] = 0;
				y += 2;
			}
			else
				y += 1;
		}
		x++;
	}
}

void	merge_right(t_context *gs)
{
	int	x;
	int	y;

	x = 0;
	while (x < 4)
	{
		y = 3;
		while (y > 0)
		{
			if (gs->grid[x][y] != 0 && gs->grid[x][y] == gs->grid[x][y - 1])
			{
				gs->grid[x][y] += gs->grid[x][y - 1];
				gs->points += gs->grid[x][y - 1];
				gs->grid[x][y - 1] = 0;
				y -= 2;
			}
			else
				y -= 1;
		}
		x++;
	}
}

void	merge_up(t_context *gs)
{
	int	x;
	int	y;
	int	flag;

	flag = 0;
	x = 0;
	while (x < 3)
	{
		y = 0;
		while (y < 4)
		{
			if (gs->grid[x][y] != 0 && gs->grid[x][y] == gs->grid[x + 1][y])
			{
				flag = 1;
				gs->grid[x][y] += gs->grid[x + 1][y];
				gs->points += gs->grid[x + 1][y];
				gs->grid[x + 1][y] = 0;
			}
			y++;
		}
		x += 2;
	}
}

void	merge_down(t_context *gs)
{
	int	x;
	int	y;
	int	flag;

	flag = 0;
	x = 1;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (gs->grid[x][y] != 0 && gs->grid[x][y] == gs->grid[x - 1][y])
			{
				flag = 1;
				gs->grid[x][y] += gs->grid[x - 1][y];
				gs->points += gs->grid[x - 1][y];
				gs->grid[x - 1][y] = 0;
			}
			y++;
		}
		x += 2;
	}
}
