/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/00/30 11:16:36 by vchesnea          #+#    #+#             */
/*   Updated: 2016/00/30 11:16:36 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

/*
** Initialize the three windows.
** Allocate and initialize room for the game's state.
** Exit on failure. Otherwise you're good to go.
** Process each keystroke according to the program's needs,
** if it's no interest then feed it to the game procedure
** to do stuff with it.
*/

int			main(void)
{
	t_context	*gamestate;
	int			key;

	if ((gamestate = ft_memalloc(sizeof(t_context))))
	{
		if (setup_windows(gamestate->windows))
		{
			while ((key = getch()))
			{
				if (key == KEY_RESIZE)
					setup_windows(gamestate->windows);
				else if (key == KEY_ESC)
					break ;
				else
					step_game(gamestate, key);
			}
			endwin();
			return (1);
		}
	}
	return (0);
}
