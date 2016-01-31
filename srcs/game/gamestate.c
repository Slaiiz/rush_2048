/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamestate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rludosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 14:09:29 by rludosan          #+#    #+#             */
/*   Updated: 2016/01/31 14:17:45 by rludosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

t_context		*newgame(void)
{
	t_context	*gs;

	if (!(gs = (t_context *)malloc(sizeof(t_context))))
		return (NULL);
	gs->grid = new_grid();
	gs->points = 0;
	return (gs);
}
