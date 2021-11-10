/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <seyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 23:09:48 by seyun             #+#    #+#             */
/*   Updated: 2021/11/11 00:06:56 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3.h"

void	read_map(t_game *game, char *line)
{
	game->lst = ft_lstnew(ft_strdup(line));
	free(line);
	while (get_next_line(game->fd, &line) > 0)
	{
		if (line[0] == EMPTY_LINE)
			break ;
		ft_lstadd_back(&game->lst, ft_lstnew(ft_strdup(line)));
		free(line);
	}
	allocate_map(game, game->lst);
	
