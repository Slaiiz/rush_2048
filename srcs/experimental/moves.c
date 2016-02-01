/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 19:01:38 by vchesnea          #+#    #+#             */
/*   Updated: 2016/01/01 19:01:38 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	merge_index(int *grid, int dst, int src, int side, int allow)
{
	if (grid[dst] == 0 && grid[src] != 0)
	{
		grid[dst] = grid[src];
		grid[src] = 0;
		if (side & LEFT && (dst & 3))
			merge_index(grid, dst - 1, dst, LEFT);
		else if (side & UP && (dst > 3))
			merge_index(grid, dst - 4, dst, UP);
		else if (side & RIGHT && ((dst + 1) & 3))
			merge_index(grid, dst + 1, dst, RIGHT;
		else if (side & DOWN && (dst < 12))
			merge_index(grid, dst + 4, dst, DOWN);
		return (0);
	}
	else if (allow && grid[dst] == grid[src])
	{
		grid[dst] = 2 * grid[src];
		grid[src] = 0;
		return (grid[dst]);
	}
	return (0);
}

static int	shift_index(int *grid, int index, int side)
{
	int		points;

	if (side & LEFT)
		while (index & 3)
			if ((points = merge_index(grid, index - 1, index, side, 1))
				break ;
	return (points);
}

static int	scan_neighbors(int *grid, int index)
{
	int		neighbors;
	int		value;

	neighbors = 0;
	value = grid[index];
	if (index > 1 && grid[index - 1] == value)
		neighbors++;
	if (index > 3 && grid[index - 4] == value)
		neighbors++;
	if (((index + 1) & 3) && grid[index + 1] == value)
		neighbors++;
	if (index < 12 && grid[index + 4] == value)
		neighbors++;
	return (neighbors);
}

e_const		search_grid(int *grid)
{
	int		index;

	index = 0;
	while (index < 16)
		if (grid[index++] == WIN_VALUE)
			return (WIN);
	return (CONTINUE);
}
