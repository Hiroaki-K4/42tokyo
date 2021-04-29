/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 22:14:16 by hkubo             #+#    #+#             */
/*   Updated: 2021/04/29 18:19:40 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

#define screenWidth 640
#define screenHeight 480
#define mapWidth 24
#define mapHeight 24

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

typedef struct	s_info {
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	void	*mlx;
	void	*win;
	double	moveSpeed;
	double	rotSpeed;
}				t_info;

// int             key_hook(int keycode, t_vars *vars)
// {
// 	printf("keycode: %d\n", keycode);
//     printf("Hello from key_hook!\n");
// }

int             key_press(int keycode, t_info *info)
{
	if (keycode == 65307)
		exit(0);
	return (0);
}

void verLine(t_info *info, int x, int y1, int y2, int color)
{
	while (y1 <= y2)
	{
		mlx_pixel_put(info->mlx, info->win, x, y1, color);
		y1++;
	}
}

void main_loop(t_info *info)
{
	int x;
	double posX;
	double posY;  //x and y start position
	double dirX;
	double dirY; //initial direction vector
	double planeX;
	double planeY; //the 2d raycaster version of camera plane
	double time; //time of current frame
	double oldTime; //time of previous frame
	double cameraX;
	double rayDirX;
	double rayDirY;
	int mapX;
	int mapY;
	//length of ray from current position to next x or y-side
	double sideDistX;
	double sideDistY;
	double deltaDistX;
	double deltaDistY;
	double perpWallDist;
	//what direction to step in x or y-direction (either +1 or -1)
	int stepX;
	int stepY;
	int hit; //was there a wall hit?
	int side; //was a NS or a EW wall hit?
	int lineHeight;
	int drawStart;
	int drawEnd;
	
	posX = 22;
	posY = 12;  //x and y start position
	dirX = -1;
	dirY = 0; //initial direction vector
	planeX = 0;
	planeY = 0.66; //the 2d raycaster version of camera plane
	time = 0; //time of current frame
	oldTime = 0; //time of previous frame
	hit = 0;
	x = 0;
	while (x < screenWidth)
	{
		//calculate ray position and direction
		cameraX = 2 * x / (double)screenWidth - 1;
		rayDirX = dirX + planeX * cameraX;
		rayDirY = dirY + planeY * cameraX;
		//which box of the map we're in
		mapX = (int)posX;
		mapY = (int)posY;
		//length of ray from one x or y-side to next x or y-side
		double deltaDistX = fabs(1 / rayDirX);
		double deltaDistY = fabs(1 / rayDirY);
		//calculate step and initial sideDist
		if(rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - posX) * deltaDistX;
		}
		if(rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - posY) * deltaDistY;
		}
		//perform DDA
		while (hit == 0)
		{
			//jump to next map square, OR in x-direction, OR in y-direction
			if(sideDistX < sideDistY)
			{
			sideDistX += deltaDistX;
			mapX += stepX;
			side = 0;
			}
			else
			{
			sideDistY += deltaDistY;
			mapY += stepY;
			side = 1;
			}
			//Check if ray has hit a wall
			if (worldMap[mapX][mapY] > 0) 
			hit = 1;
		}
		//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
		if(side == 0) 
			perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY;
		//Calculate height of line to draw on screen
		lineHeight = (int)(screenHeight / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		drawStart = -lineHeight / 2 + screenHeight / 2;
		if (drawStart < 0)
			drawStart = 0;
		drawEnd = lineHeight / 2 + screenHeight / 2;
		if (drawEnd >= screenHeight)
			drawEnd = screenHeight - 1;

		//choose wall color
		// ColorRGB color;
		int color;
		if (worldMap[mapX][mapY] == 1)
			color = 0xFF0000;
		else if (worldMap[mapX][mapY] == 2)
			color = 0x00FF00;
		else if (worldMap[mapX][mapY] == 3)
			color = 0x0000FF;
		else if (worldMap[mapX][mapY] == 4)
			color = 0xFFFFFF;
		else
			color = 0xFFFF00;
		//give x and y sides different brightness
		if(side == 1) 
			color = color / 2;

		//draw the pixels of the stripe as a vertical line
		verLine(info, x, drawStart, drawEnd, color);
		x++;
	}
}


    
    //move forward if no wall in front of you
//     if(keyDown(SDLK_UP))
//     {
//       if(worldMap[int(posX + dirX * moveSpeed)][int(posY)] == false) posX += dirX * moveSpeed;
//       if(worldMap[int(posX)][int(posY + dirY * moveSpeed)] == false) posY += dirY * moveSpeed;
//     }
//     //move backwards if no wall behind you
//     if(keyDown(SDLK_DOWN))
//     {
//       if(worldMap[int(posX - dirX * moveSpeed)][int(posY)] == false) posX -= dirX * moveSpeed;
//       if(worldMap[int(posX)][int(posY - dirY * moveSpeed)] == false) posY -= dirY * moveSpeed;
//     }
//     //rotate to the right
//     if(keyDown(SDLK_RIGHT))
//     {
//       //both camera direction and camera plane must be rotated
//       double oldDirX = dirX;
//       dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
//       dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
//       double oldPlaneX = planeX;
//       planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
//       planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
//     }
//     //rotate to the left
//     if(keyDown(SDLK_LEFT))
//     {
//       //both camera direction and camera plane must be rotated
//       double oldDirX = dirX;
//       dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
//       dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
//       double oldPlaneX = planeX;
//       planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
//       planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
//     }
//   }
// }

int	main(int argc, char *argv[])
{
	int i;
	int fd;
	int buffer_size;
	char *line;
	char *cub_path;
	void    *mlx;
	void    *mlx_win;
	t_info info;

	// if (argc != 2)
	// {
	// 	printf("Error\n");
	// 	return (-1);
	// }
	// buffer_size = 10;
    // fd = open(argv[1], O_RDONLY);
	// do
	// {
	// 	i = get_next_line(fd, &line, buffer_size);
	// 	printf("~~~fd: %d line: %s return: %d~~~\n", fd, line, i);
	// 	free(line);
	// } while (i > 0);
	// cub_path = argv[1];
	// i = ft_strlen(cub_path);
	// printf("len: %i\n", i);
	// printf("path: %s\n", cub_path);
	// argv[0] = "aa";
	
	
	info.mlx = mlx_init();
    info.win = mlx_new_window(info.mlx, screenWidth, screenHeight, "Raycaster!");
	mlx_loop_hook(info.mlx, &main_loop, &info);
    mlx_hook(info.win, 2, 1L<<0, &key_press, &info);
    // mlx_hook(vars.win, 2, 1L<<18, resize_display, &vars);
    mlx_loop(info.mlx);
	// return (argc);
}