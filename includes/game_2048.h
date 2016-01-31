/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2048.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 11:16:36 by vchesnea          #+#    #+#             */
/*   Updated: 2016/01/31 14:40:27 by vchesnea         ###   ########.fr       */
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

# define KEY_ESCAPE	27
# define KEY_RETURN	10

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

/*
** Enumerators for accessing *windows[]
*/

enum	e_display
{
	STDSCR = 0,
	HIGHSCORES = 1,
	GAMEWINDOW = 2,
	SCORE = 3
};

typedef struct	s_context
{
	int			is_running;
	int			points;
	WINDOW		*windows[4];
	int			**grid;
}				t_context;

void			draw_grid(WINDOW *c);
void			fill_slot(WINDOW *c, int slot, int number);
void			step_game(t_context *gamestate, int key);
int				setup_windows(WINDOW **windows);

int				**new_grid(void);
int				**copy_grid(int **grid);
void			delete_grid(t_context *gs);
void			collide_left(t_context *gs);
void			collide_right(t_context *gs);
void			collide_up(t_context *gs);
void			collide_down(t_context *gs);
void			merge_left(t_context *gs);
void			merge_right(t_context *gs);
void			merge_up(t_context *gs);
void			merge_down(t_context *gs);
int				move_diff(int **before, int **after);
int				move_left(t_context *gs);
int				move_right(t_context *gs);
int				move_up(t_context *gs);
int				move_down(t_context *gs);
int				gameover(t_context *gs);
void			addnum(t_context *gs);

#endif
