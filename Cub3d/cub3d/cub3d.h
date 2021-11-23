/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <seyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:35:33 by seyun             #+#    #+#             */
/*   Updated: 2021/11/23 22:43:24 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <stdlib.h>

# define EMPTY '0'
# define WALL '1'
# define SPRTIE '2'

# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3
# define SPR 4
# define FLOOR 5
# define CEILING 6
# define TILE 32

# define MAP_START -1
# define EMPTY_LINE '\0'

typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		fd;
	t_tex	tex;
	t_list	*lst;
	t_img	img;
	t_player	player;
	int		map_width;
	int		map_height;
	char	*line;
	char	**map;
}	t_game;

typedef struct s_tex
{
	char	path[6];
	int		floor;
	int		ceiling;
}	t_tex;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	move_speed;
	double	rot_speed;
	char	dir;
}	t_player;

typedef struct s_img
{
	void	*ptr;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
	int		width;
	int		height;
}	t_img;


#endif
