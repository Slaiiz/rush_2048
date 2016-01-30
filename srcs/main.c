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

int			main(void)
{
	WINDOW	*highscores;
	WINDOW	*gamewindow;
	WINDOW	*score;
	int		key;

	if (setup_windows(&highscores, &gamewindow, &score))
	{
		while ((key = getch()))
		{
			if (key == KEY_RESIZE)
				setup_windows(&highscores, &gamewindow, &score);
			else if (key == KEY_ESC)
				break ;
		}
		endwin();
		return (1);
	}
	return (0);
}
