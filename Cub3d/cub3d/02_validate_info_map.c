/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_validate_info_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <seyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 23:09:02 by seyun             #+#    #+#             */
/*   Updated: 2021/11/10 23:13:39 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	validate_info(t_game *game)
{
	if (!game->tex.path[NORTH] || !game->tex.path[SOUTH]
			|| !game->tex.path[WEST] || !game->tex.path[EAST]
			|| !game->tex.path[SPR]
			|| game->tex.floor || game->tex.ceiling == -1)
		ft_strexit("ERROR: Texture Info Missing!");
}

