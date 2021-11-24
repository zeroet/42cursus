/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <seyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:35:33 by seyun             #+#    #+#             */
/*   Updated: 2021/11/25 00:37:07 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <signal.h>

# define TITLE "cub3D"
# define EMPTY '0'
# define WALL '1'

# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3
# define FLOOR 4
# define CEILING 5

# define PI 3.1415926535897
# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_EXIT 17
# define TEX_WIDTH
# define TEX_HEIGHT

# define KEY_A 0
# define KEY_D 2
# define KEY_S 1
# define KEY_W 13
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_ESC 53

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
	int		**buf;
	int		width;
	int		height;
}	t_game;

typedef struct s_tex
{
	char	*path[5];
	int		tile[5][TEX_HEIGHT * TEX_WIDTH];
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
