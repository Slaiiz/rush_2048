/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_score.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rludosan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 14:01:54 by rludosan          #+#    #+#             */
/*   Updated: 2016/01/31 18:11:40 by rludosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

int			save_score(char *player, int score)
{
	int		fd;
	char	*line;
	char	*tmp;
	char	*tmp_score;
	int		ret;

	ret = 0;
	if ((tmp_score = ft_itoa(score)))
		if ((line = ft_strjoin(player, " => ")))
			if ((tmp = ft_strjoin(line, tmp_score)))
			{
				free(line);
				free(tmp_score);
				line = tmp;
				if ((fd = open("score.txt", O_CREAT | O_RDWR | O_APPEND, 0777)) != -1)
				{
					ret += write(fd, line, ft_strlen(line));
					ret += write(fd, "\n", 1);
					close(fd);
					return ((ret < 0) ? 0 : 1);
				}
			}
	return (0);
}
