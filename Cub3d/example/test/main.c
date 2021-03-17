/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 12:27:03 by seyun             #+#    #+#             */
/*   Updated: 2021/03/17 22:56:22 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define mapWidth 24
#define mapHeight 24
#define screenWidth 640
#define screenHeight 480

typedef struct	s_info
{
	double playerPositionX;
	double playerPositionY;
	double directionVectorX;
	double dircetionVectorY;
	double planeX;
	double planeY;
	void	*mlx;
	void	*win;
	double	moveSpeed;
	double	rotSpeed;
}				t_info;

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int main_loop(t_info *info)
{
	int x;

	x = 0;
	while (x < screenWidth)
	{
		//cameraX = 카메라 평면에서 몇분위에 있는지 계산하는식
		double cameraX = (2 * x / (double)(screenWidth)) - 1;
		// 광선의 방향 방향벡터 (-1.0)  + 카메라 평면 분할에 연결하는 벡터선
		double rayDirectionX = info->directionVectorX + info->planeX * cameraX;
		double rayDirectionY = info->directionVectorY + info->planeY * cameraY;
		//DDA
		//플레이어 위치
		int mapX = (int)(info->playerPositionX);
		int mapY = (int)(info->playerPositionY);
		double sideDistX;
		double sideDistY;
		double deltaDistX = fabs(1 / rayDirectionX);
		double deltaDistY = fabs(1 / rayDirectionY);
		double prepWallDist;
		int stepX;
		int stepY;



int main()
{
	t_info info;
	info.mlx = mlx_init();

	info.playerPositionX = 12;
	info.playerPositionY = 5;
	info.directionVectorX = -1;
	info.directionVectorY = 0;
	info.planeX = 0;
	info.plnaeY = 0.66;
	info.moveSpeed = 0.05;
	info.rotSpeed = 0.05;

	info.win = mlx_new_window(info.mlx, screenWidth, screenHeight, "mlx");
	mlx_loop_hook(info.mlx, &main_loop, &info);
	mlx_hook(info.win, X_EVENT_KEY_PRESS, 0, &key_press, &info);
	mlx_loop(info.mlx);
}
