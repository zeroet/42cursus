/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 13:46:04 by seyun             #+#    #+#             */
/*   Updated: 2021/03/10 12:55:53 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"

typedef struct s_data
{
	void *mlx;
	void *win;
	void *img;
	char *addr;
	int	bits_per_pixel;
	int line_length;
	int endian;
	int width;
	int height;
}		t_data;

int draw(t_data *data)
{
	int num=400;

	for(int i=0;i<num;i++)
	{
		for(int j=num-1;j>i;j--)
		{
			mlx_pixel_put(data->mlx, data->win, i, j, 0x00FF0000);
		}
		for(int j=0;j<2*i+1;j++)
		{
			mlx_pixel_put(data->mlx, data->win, i, j, 0x00FFFF00);
	    }
		//mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	return (0);
}

int main(void)
{
	t_data data;

	data.mlx = mlx_init();
	data.width = 800;
	data.height = 600;
	data.win = mlx_new_window(data.mlx, data.width, data.height, "hello");
	data.img = mlx_new_image(data.mlx, data.width, data.height);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	mlx_loop_hook(data.mlx, draw, &data);
	mlx_loop(data.mlx);
}
