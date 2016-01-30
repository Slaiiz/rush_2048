/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2048.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/00/30 11:16:36 by vchesnea          #+#    #+#             */
/*   Updated: 2016/00/30 11:16:36 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_2048_H
# define GAME_2048_H

# include <ncurses.h>
# include <menu.h>
# include "libft.h"

# define CENTER(size, length)	(size - length) / 2

/*
** Manual makes no mention of this key that I know.
*/
# define KEY_ESC	27

/*
** Highscores window's proportional scale
*/
# define WINA_X	(COLS / 10 * 3)
# define WINA_Y	(LINES / 10 * 9)

/*
** Gamewindow window's proportional scale
*/
# define WINB_X	(COLS / 10 * 7 + COLS % 10)
# define WINB_Y (LINES / 10 * 10 + LINES % 10)

/*
** Score window's proportional scale
*/
# define WINC_X	(COLS / 10 * 3)
# define WINC_Y	(LINES / 10 * 1 + LINES % 10)

/*
** WIN_VALUE: Victory condition
*/
enum	e_const
{
	WIN_VALUE = 2048
};

void	update_score(WINDOW *c, int points);
void	setup_text(WINDOW *a, WINDOW *b, WINDOW *c);
int		setup_windows(WINDOW **a, WINDOW **b, WINDOW **c);

#endif
