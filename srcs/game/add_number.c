/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rludosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 12:12:30 by rludosan          #+#    #+#             */
/*   Updated: 2016/01/31 16:39:10 by rludosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

/*
** Spawn a random number of value 2 or 4 somewhere on the map.
** The random number generator is constantly seeded thanks to the time.
** The more you exploit the same seed the less the 'randomness' factor
** will be felt, since we can't indefinitely generate a statistically
** imprevisible number using the same seed.
** Binary shifts are used so that we don't waste the upper bits of the numbers
** which we would otherwise discard. This effectively increases randomness.
** @param t_context *gs		- The state of the game
*/

void			add_number(t_context *gs)
{
	time_t	tm;
	int		x;
	int		y;

	x = 0;
	y = 0;
	srand((size_t)time(&tm));
	while (1)
	{
		if (!x || !y)
		{
			x = rand();
			y = rand();
		}
		if (gs->grid[x & 3][y & 3] == 0)
			break ;
		x >>= 1;
		y >>= 1;
	}
	gs->grid[x & 3][y & 3] = 2 * (rand() & 1) + 2;
	return ;
}
