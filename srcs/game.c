/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchesnea <vchesnea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/00/30 11:16:36 by vchesnea          #+#    #+#             */
/*   Updated: 2016/00/30 11:16:36 by vchesnea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

void	update_score(WINDOW *c, int points)
{
	char	*s;

	s = "Points:";
	mvwaddstr(c, CENTER(WINC_Y, 1), 2, s);
	s = ft_itoa(points);
	mvwaddstr(c, CENTER(WINC_Y, ft_strlen(s)), WINC_X - ft_strlen(s) - 2, s);
	free(s);
}
