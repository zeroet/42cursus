/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_run_program.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 22:06:21 by seyun             #+#    #+#             */
/*   Updated: 2021/11/23 22:07:07 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_player(t_player *player, double rot_speed)
{
	double old_dir_x;
	double old_dir_y;

	old_dir_x = player->dir_x;
