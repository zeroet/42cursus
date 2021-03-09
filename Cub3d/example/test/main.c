/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 12:27:03 by seyun             #+#    #+#             */
/*   Updated: 2021/03/09 14:01:16 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"

typedef struct	s_window
{
	void	*mlx;
	void	*win;

	int		width;
	int		height;

	int		row_count;
	int		column_count;
	int		grid_color;
}				t_window;

int		draw_grid(t_window *window)
{
	int	draw_position;
	int	i;

	i = 1;
	while (i< window->row_count)
	{
		draw_position = 0;
		while (draw_position <= window->width){
			mlx_pixel_put(window->mlx, window->win, draw_position, i * (window->height / window->row_count),window->grid_color);
			draw_position++;
		}
		i++;
	}
	i = 1;
	while (i< window->column_count)
	{
		draw_position = 0;
		while (draw_position <= window->width){
			mlx_pixel_put(window->mlx, window->win, i * (window->width/ window->column_count), draw_position,window->grid_color);
			draw_position++;
		}
		i++;
	}
	return (0);
}

int		main(void)
{
	t_window window;

	window.width = 500;
	window.height = 500;
	window.row_count = 10;
	window.column_count = 10;
	window.grid_color = 0x00FFFF;
	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, window.width, window.height, "mlx_grid");
	mlx_loop_hook(window.mlx, draw_grid, &window);
	mlx_loop(window.mlx);
}
