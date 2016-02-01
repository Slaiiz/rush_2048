/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 17:12:02 by vchesnea          #+#    #+#             */
/*   Updated: 2016/01/01 17:12:02 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static int		new_grid(int **grid)
{
	if (*grid != NULL)
		free(*grid);
	if ((*grid = ft_memalloc(sizeof(int) * (4 * 4))) == NULL)
		return (0);
	spawn_number(gamestate);
	spawn_number(gamestate);
	return (1);
}

e_const			make_move(t_context *gamestate, int side)
{
	int		*grid;
	int		index;
	int		stuck;

	stuck = 0;
	index = -1;
	grid = gamestate->grid;
	while (++index < 16)
	{
		if (grid[index] != 0)
		{
			if (!scan_neighbors(grid, index))
				stuck++;
			continue ;
		}
		gamestate->points += shift_index(grid, index, side);
	}
	if (stuck == 16)
		return (LOSE);
	return (search_grid());
}

int				new_game(t_context *gamestate)
{
	WINDOW	**windows;

	windows = gamestate->windows;
	if (ft_bitscan(WIN_VALUE) != 1 || WIN_VALUE == 1)
	{
		mvwaddstr(windows[SCORE], CENTER(WINC_Y, 1), 2, "I AIN'T RUNNIN' THAT");
		wrefresh(windows[SCORE]);
		return ;
	}
	gamestate->is_running = 1;
	mvwhline(windows[HIGHSCORES], WINA_Y - 2, 1, ' ', WINA_X - 2);
	wrefresh(windows[HIGHSCORES]);
	if (!new_grid(&gamestate->grid))
		return (0);
	update_score(gamestate);
	draw_grid(gamestate);
}
