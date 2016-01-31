/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rludosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 13:24:20 by rludosan          #+#    #+#             */
/*   Updated: 2016/01/31 16:40:37 by rludosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

void	delete_grid(t_context *gs)
{
	int	x;

	x = 0;
	while (x < 16)
		free(gs->grid[x++]);
}

int		**copy_grid(int **grid)
{
	int	**copy;
	int	x;
	int	y;

	copy = new_grid();
	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			copy[x][y] = grid[x][y];
			y++;
		}
		x++;
	}
	return (copy);
}

int		**new_grid(void)
{
	int	**grid;
	int	x;
	int	y;

	grid = (int **)malloc(sizeof(int *) * 16);
	x = 0;
	while (x < 16)
		grid[x++] = (int *)malloc(sizeof(int));
	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
			grid[x][y++] = 0;
		x++;
	}
	return (grid);
}
