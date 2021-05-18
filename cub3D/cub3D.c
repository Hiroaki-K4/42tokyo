/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 15:18:03 by yohlee            #+#    #+#             */
/*   Updated: 2021/05/18 21:55:56 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define X_EVENT_KEY_PRESS	2
#define X_EVENT_KEY_EXIT	17
#define texWidth 64
#define texHeight 64
#define mapWidth 24
#define mapHeight 24
#define numSprites 19
#define K_W 119
#define K_S 115
#define K_D 100
#define K_A 97
#define K_ESC 65307

int		spriteOrder[numSprites];
double	spriteDistance[numSprites];

struct	Sprite
{
	double		x;
	double		y;
	int			texture;
};

struct Sprite	sprite[numSprites] =
{
	// {20.5, 11.5, 10}, //green light in front of playerstart
	// //green lights in every room
	// {18.5,4.5, 10},
	// {10.0,4.5, 10},
	// {10.0,12.5,10},
	// {3.5, 6.5, 10},
	// {3.5, 20.5,10},
	// {3.5, 14.5,10},
	// {14.5,20.5,10},

	//row of pillars in front of wall: fisheye test
	// {18.5, 10.5, 9},
	// {18.5, 11.5, 9},
	// {18.5, 12.5, 9},

	//some barrels around the map
	// {21.5, 1.5, 8},
	// {15.5, 1.5, 8},
	// {16.0, 1.8, 8},
	// {16.2, 1.2, 8},
	// {3.5,  2.5, 8},
	// {9.5, 15.5, 8},
	// {10.0, 15.1,8},
	// {3.0, 21.0, 8},
	{9.0, 4.0, 8},
	// {10.5, 15.8,8},
};

typedef struct	s_img
{
	void	*img;
	int		*data;

	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}				t_img;

typedef struct		s_pair
{
	double	first;
	int		second;
}					t_pair;

typedef struct		s_rgb
{
	int red;
	int green;
	int blue;
}					t_rgb;


typedef struct		s_cub
{
	int width;
	int height;
	int count;
	char **map;
	int **map_matrix;
	int map_x;
	int map_y;
	int size;
	char *n_texture;
	char *s_texture;
	char *w_texture;
	char *e_texture;
	char *sprite;
	int floor_dec;
	int ceiling_dec;
	t_rgb floor;
	t_rgb ceiling;
}					t_cub;

typedef struct	s_info
{
	double posX;
	double posY;
	double dirX;
	double dirY;
	double planeX;
	double planeY;
	// double	zBuffer[width];
	double	*zBuffer;
	void	*mlx;
	void	*win;
	t_img	img;
	// int		buf[height][width];
	int		**buf;
	int		**texture;
	double	moveSpeed;
	double	rotSpeed;
	t_cub cub_list;
}				t_info;

void	sort_order(t_pair *orders, int amount)
{
	t_pair	tmp;

	for (int i = 0; i < amount; i++)
	{
		for (int j = 0; j < amount - 1; j++)
		{
			if (orders[j].first > orders[j + 1].first)
			{
				tmp.first = orders[j].first;
				tmp.second = orders[j].second;
				orders[j].first = orders[j + 1].first;
				orders[j].second = orders[j + 1].second;
				orders[j + 1].first = tmp.first;
				orders[j + 1].second = tmp.second;
			}
		}
	}
}

void	sortSprites(int *order, double *dist, int amount)
{
	t_pair	*sprites;

	//std::vector<std::pair<double, int>> sprites(amount);
	sprites = (t_pair*)malloc(sizeof(t_pair) * amount);
	for (int i = 0; i < amount; i++)
	{
		sprites[i].first = dist[i];
		sprites[i].second = order[i];
	}
	sort_order(sprites, amount);
	//std::sort(sprites.begin(), sprites.end());
	for (int i = 0; i < amount; i++)
	{
		dist[i] = sprites[amount - i - 1].first;
		order[i] = sprites[amount - i - 1].second;
	}
	free(sprites);
}

char			*ft_itoa_hex(unsigned int n, char *arg)
{
	int				len;
	unsigned int	i;
	unsigned int	j;
	char			*ans;

	i = n / 16;
	if (i != 0)
	{
		len = 2;
		while (i > 16)
		{
			len++;
			i = i / 16;
		}
	}
	else
		len = 1;
	if (!(ans = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ans[len] = '\0';
	i = n;
	len--;
	if (i == 0)
	{
		ans[0] = '0';
		return (ans);
	}
	while (i > 0)
	{
		j = i % 16;
		ans[len] = arg[j];
		i = i / 16;
		len--;
	}
	return (ans);
}

// int	worldMap[mapWidth][mapHeight] =
// 									{
// 										{8,8,8,8,8,8,8,8,8,8,8,4,4,6,4,4,6,4,6,4,4,4,6,4},
// 										{8,0,0,0,0,0,0,0,0,0,8,4,0,0,0,0,0,0,0,0,0,0,0,4},
// 										{8,0,3,3,0,0,0,0,0,8,8,4,0,0,0,0,0,0,0,0,0,0,0,6},
// 										{8,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
// 										{8,0,3,3,0,0,0,0,0,8,8,4,0,0,0,0,0,0,0,0,0,0,0,4},
// 										{8,0,0,0,0,0,0,0,0,0,8,4,0,0,0,0,0,6,6,6,0,6,4,6},
// 										{8,8,8,8,0,8,8,8,8,8,8,4,4,4,4,4,4,6,0,0,0,0,0,6},
// 										{7,7,7,7,0,7,7,7,7,0,8,0,8,0,8,0,8,4,0,4,0,6,0,6},
// 										{7,7,0,0,0,0,0,0,7,8,0,8,0,8,0,8,8,6,0,0,0,0,0,6},
// 										{7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,6,0,0,0,0,0,4},
// 										{7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,6,0,6,0,6,0,6},
// 										{7,7,0,0,0,0,0,0,7,8,0,8,0,8,0,8,8,6,4,6,0,6,6,6},
// 										{7,7,7,7,0,7,7,7,7,8,8,4,0,6,8,4,8,3,3,3,0,3,3,3},
// 										{2,2,2,2,0,2,2,2,2,4,6,4,0,0,6,0,6,3,0,0,0,0,0,3},
// 										{2,2,0,0,0,0,0,2,2,4,0,0,0,0,0,0,4,3,0,0,0,0,0,3},
// 										{2,0,0,0,0,0,0,0,2,4,0,0,0,0,0,0,4,3,0,0,0,0,0,3},
// 										{1,0,0,0,0,0,0,0,1,4,4,4,4,4,6,0,6,3,3,0,0,0,3,3},
// 										{2,0,0,0,0,0,0,0,2,2,2,1,2,2,2,6,6,0,0,5,0,5,0,5},
// 										{2,2,0,0,0,0,0,2,2,2,0,0,0,2,2,0,5,0,5,0,0,0,5,5},
// 										{2,0,0,0,0,0,0,0,2,0,0,0,0,0,2,5,0,5,0,5,0,5,0,5},
// 										{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5},
// 										{2,0,0,0,0,0,0,0,2,0,0,0,0,0,2,5,0,5,0,5,0,5,0,5},
// 										{2,2,0,0,0,0,0,2,2,2,0,0,0,2,2,0,5,0,5,0,0,0,5,5},
// 										{2,2,2,2,1,2,2,2,2,2,2,1,2,2,2,5,5,5,5,5,5,5,5,5}
// 									};

void	draw(t_info *info)
{
	for (int y = 0; y < info->cub_list.height; y++)
	{
		for (int x = 0; x < info->cub_list.width; x++)
		{
			info->img.data[y * info->cub_list.width + x] = info->buf[y][x];
		}
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}

void	calc(t_info *info)
{
	int	x;

	if (!(info->zBuffer = (double *)malloc(sizeof(double) * (info->cub_list.width))))
		return (-1);
	x = 0;
	while (x < info->cub_list.width)
	{
		double cameraX = 2 * x / (double)info->cub_list.width - 1;
		double rayDirX = info->dirX + info->planeX * cameraX;
		double rayDirY = info->dirY + info->planeY * cameraX;
		
		int mapX = (int)info->posX;
		int mapY = (int)info->posY;

		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;
		
		 //length of ray from one x or y-side to next x or y-side
		double deltaDistX = fabs(1 / rayDirX);
		double deltaDistY = fabs(1 / rayDirY);
		double perpWallDist;
		
		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;
		
		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?

		printf("DirX: %f DirY: %f\n", info->dirX, info->dirY);
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (info->posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - info->posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (info->posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - info->posY) * deltaDistY;
		}

		while (hit == 0)
		{
			//jump to next map square, OR in x-direction, OR in y-direction
			if (sideDistX < sideDistY)
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
			// printf("mapx: %d mapy: %d\n", mapX, mapY);
			// printf("point: %d\n", info->cub_list.map_matrix[mapY][mapX]);
			if (info->cub_list.map_matrix[mapX][mapY] > 0) hit = 1;
			// if (worldMap[mapX][mapY] > 0) hit = 1;
			// if (info->cub_list.map_matrix[mapY][mapX] > 0) hit = 1;
		}
		if (side == 0)
			perpWallDist = (mapX - info->posX + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - info->posY + (1 - stepY) / 2) / rayDirY;

		//Calculate height of line to draw on screen
		int lineHeight = (int)(info->cub_list.height / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + info->cub_list.height / 2;
		if(drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + info->cub_list.height / 2;
		if(drawEnd >= info->cub_list.height)
			drawEnd = info->cub_list.height - 1;

		// texturing calculations
		// int texNum = worldMap[mapX][mapY];
		int texNum = info->cub_list.map_matrix[mapX][mapY];
		if (texNum == 1)
		{
			if (fabs(info->dirX) >= fabs(info->dirY) && info->dirX <= 0)
			{
				if (side == 1)
				{
					if (rayDirY > 0)
						texNum = 3;
					else
						texNum = 2;
				}
				else
					texNum = 0;
			}
			else if (fabs(info->dirX) >= fabs(info->dirY) && info->dirX >= 0)
			{
				if (side == 1)
				{
					if (rayDirY > 0)
						texNum = 3;
					else
						texNum = 2;
				}
				else
					texNum = 1;
			}
			else if (fabs(info->dirY) >= fabs(info->dirX) && 0 >= info->dirY)
			{
				if (side == 0)
				{
					if (rayDirX > 0)
						texNum = 1;
					else
						texNum = 0;
				}
				else
					texNum = 2;
			}
			else if (fabs(info->dirY) >= fabs(info->dirX) && info->dirY >= 0)
			{
				if (side == 0)
				{
					if (rayDirX > 0)
						texNum = 1;
					else
						texNum = 0;
				}
				else
				texNum = 3;
			}
		}

		// calculate value of wallX
		double wallX;
		if (side == 0)
			wallX = info->posY + perpWallDist * rayDirY;
		else
			wallX = info->posX + perpWallDist * rayDirX;
		wallX -= floor(wallX);

		// x coordinate on the texture
		int texX = (int)(wallX * (double)texWidth);
		if (side == 0 && rayDirX > 0)
			texX = texWidth - texX - 1;
		if (side == 1 && rayDirY < 0)
			texX = texWidth - texX - 1;

		// How much to increase the texture coordinate perscreen pixel
		double step = 1.0 * texHeight / lineHeight;
		// Starting texture coordinate
		double texPos = (drawStart - info->cub_list.height / 2 + lineHeight / 2) * step;
		// printf("ok\n");
		for (int y = 0; y < drawStart; y++)
		{
			// printf("drawStart: %d\n", drawStart);
			// printf("x: %d y: %d\n", x, y);
			// info->buf[y][x] = 8355711;
			info->buf[y][x] = info->cub_list.ceiling_dec;
		}
		for (int y = drawStart; y < drawEnd; y++)
		{
			// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
			int texY = (int)texPos & (texHeight - 1);
			texPos += step;
			int color = info->texture[texNum][texHeight * texY + texX];
			// printf("color: %d\n", color);
			// make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
			if (side == 1)
				color = (color >> 1) & 8355711;
			info->buf[y][x] = color;
			// printf("color: %d\n", color);
		}
		info->zBuffer[x] = perpWallDist;
		// zBuffer[x] = perpWallDist;
		for (int y = drawEnd; y < info->cub_list.height; y++)
		{
			// info->buf[y][x] = 8355711;
			info->buf[y][x] = info->cub_list.floor_dec;
		}
		x++;
	}
	
	//SPRITE CASTING
	//sort sprites from far to close
	for(int i = 0; i < numSprites; i++)
	{
		spriteOrder[i] = i;
		spriteDistance[i] = ((info->posX - sprite[i].x) * (info->posX - sprite[i].x) + (info->posY - sprite[i].y) * (info->posY - sprite[i].y)); //sqrt not taken, unneeded
	}
	sortSprites(spriteOrder, spriteDistance, numSprites);
	//after sorting the sprites, do the projection and draw them
	for(int i = 0; i < numSprites; i++)
	{
		//translate sprite position to relative to camera
		double spriteX = sprite[spriteOrder[i]].x - info->posX;
		double spriteY = sprite[spriteOrder[i]].y - info->posY;

		//transform sprite with the inverse camera matrix
		// [ planeX   dirX ] -1                                       [ dirY      -dirX ]
		// [               ]       =  1/(planeX*dirY-dirX*planeY) *   [                 ]
		// [ planeY   dirY ]                                          [ -planeY  planeX ]

		double invDet = 1.0 / (info->planeX * info->dirY - info->dirX * info->planeY); //required for correct matrix multiplication

		double transformX = invDet * (info->dirY * spriteX - info->dirX * spriteY);
		double transformY = invDet * (-info->planeY * spriteX + info->planeX * spriteY); //this is actually the depth inside the screen, that what Z is in 3D, the distance of sprite to player, matching sqrt(spriteDistance[i])

		int spriteScreenX = (int)((info->cub_list.width / 2) * (1 + transformX / transformY));

		//parameters for scaling and moving the sprites
		#define uDiv 1
		#define vDiv 1
		#define vMove 0.0
		int vMoveScreen = (int)(vMove / transformY);

		//calculate height of the sprite on screen
		int spriteHeight = (int)fabs((info->cub_list.height / transformY) / vDiv); //using "transformY" instead of the real distance prevents fisheye
		//calculate lowest and highest pixel to fill in current stripe
		int drawStartY = -spriteHeight / 2 + info->cub_list.height / 2 + vMoveScreen;
		if(drawStartY < 0) drawStartY = 0;
		int drawEndY = spriteHeight / 2 + info->cub_list.height / 2 + vMoveScreen;
		if(drawEndY >= info->cub_list.height) drawEndY = info->cub_list.height - 1;

		//calculate width of the sprite
		int spriteWidth = (int)fabs((info->cub_list.height / transformY) / uDiv);
		int drawStartX = -spriteWidth / 2 + spriteScreenX;
		if(drawStartX < 0) drawStartX = 0;
		int drawEndX = spriteWidth / 2 + spriteScreenX;
		if(drawEndX >= info->cub_list.width) drawEndX = info->cub_list.width - 1;

		//loop through every vertical stripe of the sprite on screen
		for(int stripe = drawStartX; stripe < drawEndX; stripe++)
		{
			int texX = (int)((256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * texWidth / spriteWidth) / 256);
			//the conditions in the if are:
			//1) it's in front of camera plane so you don't see things behind you
			//2) it's on the screen (left)
			//3) it's on the screen (right)
			//4) ZBuffer, with perpendicular distance
			if(transformY > 0 && stripe > 0 && stripe < info->cub_list.width && transformY < info->zBuffer[stripe])
			// if(transformY > 0 && stripe > 0 && stripe < width && transformY < zBuffer[stripe])
			for(int y = drawStartY; y < drawEndY; y++) //for every pixel of the current stripe
			{
				int d = (y-vMoveScreen) * 256 - info->cub_list.height * 128 + spriteHeight * 128; //256 and 128 factors to avoid floats
				int texY = ((d * texHeight) / spriteHeight) / 256;
				int color = info->texture[sprite[spriteOrder[i]].texture][texWidth * texY + texX]; //get current color from the texture
				if((color & 0x00FFFFFF) != 0) info->buf[y][stripe] = color; //paint pixel if it isn't black, black is the invisible color
			}
		}
	}
	free(info->zBuffer);
}

int	main_loop(t_info *info)
{
	calc(info);
	draw(info);
	return (0);
}

int	key_press(int key, t_info *info)
{
	if (key == K_W)
	{
		if (!info->cub_list.map_matrix[(int)(info->posX + info->dirX * info->moveSpeed)][(int)(info->posY)])
			info->posX += info->dirX * info->moveSpeed;
		if (!info->cub_list.map_matrix[(int)(info->posX)][(int)(info->posY + info->dirY * info->moveSpeed)])
			info->posY += info->dirY * info->moveSpeed;
		// if (!worldMap[(int)(info->posX + info->dirX * info->moveSpeed)][(int)(info->posY)])
		// 	info->posX += info->dirX * info->moveSpeed;
		// if (!worldMap[(int)(info->posX)][(int)(info->posY + info->dirY * info->moveSpeed)])
		// 	info->posY += info->dirY * info->moveSpeed;
	}
	//move backwards if no wall behind you
	if (key == K_S)
	{
		if (!info->cub_list.map_matrix[(int)(info->posX - info->dirX * info->moveSpeed)][(int)(info->posY)])
			info->posX -= info->dirX * info->moveSpeed;
		if (!info->cub_list.map_matrix[(int)(info->posX)][(int)(info->posY - info->dirY * info->moveSpeed)])
			info->posY -= info->dirY * info->moveSpeed;
		// if (!worldMap[(int)(info->posX - info->dirX * info->moveSpeed)][(int)(info->posY)])
		// 	info->posX -= info->dirX * info->moveSpeed;
		// if (!worldMap[(int)(info->posX)][(int)(info->posY - info->dirY * info->moveSpeed)])
		// 	info->posY -= info->dirY * info->moveSpeed;
	}
	//rotate to the right
	if (key == K_D)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = info->dirX;
		info->dirX = info->dirX * cos(-info->rotSpeed) - info->dirY * sin(-info->rotSpeed);
		info->dirY = oldDirX * sin(-info->rotSpeed) + info->dirY * cos(-info->rotSpeed);
		double oldPlaneX = info->planeX;
		info->planeX = info->planeX * cos(-info->rotSpeed) - info->planeY * sin(-info->rotSpeed);
		info->planeY = oldPlaneX * sin(-info->rotSpeed) + info->planeY * cos(-info->rotSpeed);
	}
	//rotate to the left
	if (key == K_A)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = info->dirX;
		info->dirX = info->dirX * cos(info->rotSpeed) - info->dirY * sin(info->rotSpeed);
		info->dirY = oldDirX * sin(info->rotSpeed) + info->dirY * cos(info->rotSpeed);
		double oldPlaneX = info->planeX;
		info->planeX = info->planeX * cos(info->rotSpeed) - info->planeY * sin(info->rotSpeed);
		info->planeY = oldPlaneX * sin(info->rotSpeed) + info->planeY * cos(info->rotSpeed);
	}
	if (key == K_ESC)
		exit(0);
	return (0);
}

void	load_image(t_info *info, int *texture, char *path, t_img *img)
{
	img->img = mlx_xpm_file_to_image(info->mlx, path, &img->img_width, &img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->endian);
	for (int y = 0; y < img->img_height; y++)
	{
		for (int x = 0; x < img->img_width; x++)
		{
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
		}
	}
	mlx_destroy_image(info->mlx, img->img);
}

void	load_texture(t_info *info)
{
	t_img	img;

	load_image(info, info->texture[0], info->cub_list.n_texture, &img);
	load_image(info, info->texture[1], info->cub_list.s_texture, &img);
	load_image(info, info->texture[2], info->cub_list.w_texture, &img);
	load_image(info, info->texture[3], info->cub_list.e_texture, &img);
	load_image(info, info->texture[4], "textures/bluestone.xpm", &img);
	load_image(info, info->texture[5], "textures/mossy.xpm", &img);
	load_image(info, info->texture[6], "textures/wood.xpm", &img);
	load_image(info, info->texture[7], "textures/colorstone.xpm", &img);
	load_image(info, info->texture[8], "textures/barrel.xpm", &img);
	load_image(info, info->texture[9], "textures/pillar.xpm", &img);
	load_image(info, info->texture[10], "textures/greenlight.xpm", &img);
}

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	if (!s1 || !s2)
		return (-1);
	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int map_line_check(char **line_split)
{
	int i;
	int j;
	
	i = 0;
	while (line_split[i])
	{
		j = 0;
		while (line_split[i][j])
		{
			if (line_split[i][j] != '0' && line_split[i][j] != '1' && line_split[i][j] != '2' 
			&& line_split[i][j] != 'N' && line_split[i][j] != 'S' && line_split[i][j] != 'E' && line_split[i][j] != 'W')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_strchr_place(const char *str, int c)
{
	int	j;

	j = 0;
	while (j < (int)ft_strlen(str))
	{
		if (str[j] == c)
			return (j);
		j++;
	}
	return (-1);
}

int hex_to_decimal(char *hex)
{
	int i;
	int j;
	int ans;
	int hex_pow;
	
	ans = 0;
	printf("hex: %s\n", hex);
	i = 0;
	while (i < ft_strlen(hex))
	{
		hex_pow = 1;
		j = 0;
		while (j < i)
		{
			hex_pow *= 16;
			j++;
		}
		printf("hex_pow: %d\n", hex_pow);
		ans += hex_pow * (ft_strchr_place("0123456789ABCDEF", hex[ft_strlen(hex) - 1 - i]));
		i++;
	}
	return (ans);
}

char *make_decimal_color(t_rgb color)
{
	char *hex;
	char *red;
	char *green;
	char *blue;
	char *tmp;
	int ans;
	
	if (!(red = ft_strdup(ft_itoa_hex(color.red, "0123456789ABCDEF"))))
		return (NULL);
	if (!(green = ft_strdup(ft_itoa_hex(color.green, "0123456789ABCDEF"))))
		return (NULL);
	if (!(blue = ft_strdup(ft_itoa_hex(color.blue, "0123456789ABCDEF"))))
		return (NULL);
	if (!(hex = ft_strjoin(red, green)))
		return (NULL);
	if (!(tmp = ft_strdup(hex)))
		return (NULL);
	free(hex);
	if (!(hex = ft_strjoin(tmp, blue)))
		return (NULL);
	free(red);
	free(green);
	free(blue);
	free(tmp);
	ans = hex_to_decimal(hex);
	return (ans);
}

int line_check(char **line, t_info *info)
{
	int i;
	char *map_line;
	char **line_split;
	char **rgb_split;
	char **tmp;
	
	if (!(line_split = ft_split(line, ' ')))
		return (-1);
	if (line_split[0] == NULL)
		return (0);
	else if (i = ft_strcmp("R", line_split[0]) == 0)
	{
		info->cub_list.width = ft_atoi(line_split[1]);
		info->cub_list.height = ft_atoi(line_split[2]);
	}
	else if (i = ft_strcmp("NO", line_split[0]) == 0)
		info->cub_list.n_texture = line_split[1];
	else if (i = ft_strcmp("SO", line_split[0]) == 0)
		info->cub_list.s_texture = line_split[1];
	else if (i = ft_strcmp("WE", line_split[0]) == 0)
		info->cub_list.w_texture = line_split[1];
	else if (i = ft_strcmp("EA", line_split[0]) == 0)
		info->cub_list.e_texture = line_split[1];
	else if (i = ft_strcmp("S", line_split[0]) == 0)
		info->cub_list.sprite = line_split[1];
	else if (i = ft_strcmp("F", line_split[0]) == 0)
	{
		if (!(rgb_split = ft_split(line_split[1], ',')))
			return (-1);
		info->cub_list.floor.red = ft_atoi(rgb_split[0]);
		info->cub_list.floor.green = ft_atoi(rgb_split[1]);
		info->cub_list.floor.blue = ft_atoi(rgb_split[2]);
		info->cub_list.floor_dec = make_decimal_color(info->cub_list.floor);
	}
	else if (i = ft_strcmp("C", line_split[0]) == 0)
	{
		if (!(rgb_split = ft_split(line_split[1], ',')))
			return (-1);
		info->cub_list.ceiling.red = ft_atoi(rgb_split[0]);
		info->cub_list.ceiling.green = ft_atoi(rgb_split[1]);
		info->cub_list.ceiling.blue = ft_atoi(rgb_split[2]);
		info->cub_list.ceiling_dec = make_decimal_color(info->cub_list.ceiling);
	}
	else if (map_line_check(line_split) == 0)
	{
		info->cub_list.map_y++;
		if (!(map_line = ft_strdup(line)))
			return (-1);
		if (ft_strlen(map_line) > info->cub_list.map_x)
			info->cub_list.map_x = ft_strlen(map_line);
		if (!(tmp = (char **)malloc(sizeof(char *) * (info->cub_list.map_y))))
			return (-1);
		i = 0;
		while (i < info->cub_list.map_y - 1)
		{
			if (!(tmp[i] = (char **)malloc(sizeof(char) * (ft_strlen(map_line) + 1))))
				return (-1);
			tmp[i] = info->cub_list.map[i];
			i++;
		}
		tmp[i] = map_line;
		free(info->cub_list.map);
		info->cub_list.map = tmp;
	}
	return (0);
}

int convert_int_matrix(t_info *info)
{
	int i;
	int j;
	
	if (!(info->cub_list.map_matrix = (int **)malloc(sizeof(int *) * (info->cub_list.map_y))))
		return (-1);
	i = 0;
	while (i < info->cub_list.map_y)
	{
		if (!(info->cub_list.map_matrix[i] = (int *)malloc(sizeof(int) * (info->cub_list.map_x))))
			return (-1);
		i++;
	}
	i = 0;
	while (i < info->cub_list.map_y)
	{
		j = 0;
		if (ft_strlen(info->cub_list.map[i]) < info->cub_list.map_x)
		{
			// printf("line: %s\n", info->cub_list.map[i]);
			while (j < ft_strlen(info->cub_list.map[i]))
			{
				if (info->cub_list.map[i][j] == 'N' || info->cub_list.map[i][j] == 'S' || info->cub_list.map[i][j] == 'W' || info->cub_list.map[i][j] == 'E')
				{
					info->posX = (double)i;
					info->posY = (double)j;
				}
				if (info->cub_list.map[i][j] == 'N')
				{
					info->cub_list.map_matrix[i][j] = 0;
					info->dirX = -1.0;
					info->dirY = 0.0;
					info->planeX = 0.0;
					info->planeY = 0.66;
				}
				else if (info->cub_list.map[i][j] == 'S')
				{
					info->cub_list.map_matrix[i][j] = 0;
					info->dirX = 1.0;
					info->dirY = 0.0;
					info->planeX = 0.0;
					info->planeY = -0.66;
				}
				else if (info->cub_list.map[i][j] == 'W')
				{
					info->cub_list.map_matrix[i][j] = 0;
					info->dirX = 0.0;
					info->dirY = -1.0;
					info->planeX = -0.66;
					info->planeY = 0.0;
				}
				else if (info->cub_list.map[i][j] == 'E')
				{
					info->cub_list.map_matrix[i][j] = 0;
					info->dirX = 0.0;
					info->dirY = 1.0;
					info->planeX = 0.66;
					info->planeY = 0.0;
				}
				else if (info->cub_list.map[i][j] == ' ')
					info->cub_list.map_matrix[i][j] = 3;
				else
				{
					info->cub_list.map_matrix[i][j] = info->cub_list.map[i][j] - '0';
				}
				write(1, ft_itoa(info->cub_list.map_matrix[i][j]), 1);
				j++;
			}
			while (j < info->cub_list.map_x)
			{
				info->cub_list.map_matrix[i][j] = 3;
				write(1, ft_itoa(info->cub_list.map_matrix[i][j]), 1);
				j++;
			}
		}
		else
		{
			while (j < info->cub_list.map_x)
			{
				if (info->cub_list.map[i][j] == 'N' || info->cub_list.map[i][j] == 'S' || info->cub_list.map[i][j] == 'W' || info->cub_list.map[i][j] == 'E')
				{
					info->posX = (double)i;
					info->posY = (double)j;
				}
				if (info->cub_list.map[i][j] == 'N')
				{
					info->cub_list.map_matrix[i][j] = 0;
					info->dirX = -1.0;
					info->dirY = 0.0;
					info->planeX = 0.0;
					info->planeY = 0.66;
				}
				else if (info->cub_list.map[i][j] == 'S')
				{
					info->cub_list.map_matrix[i][j] = 0;
					info->dirX = 1.0;
					info->dirY = 0.0;
					info->planeX = 0.0;
					info->planeY = -0.66;
				}
				else if (info->cub_list.map[i][j] == 'W')
				{
					info->cub_list.map_matrix[i][j] = 0;
					info->dirX = 0.0;
					info->dirY = -1.0;
					info->planeX = -0.66;
					info->planeY = 0.0;
				}
				else if (info->cub_list.map[i][j] == 'E')
				{	
					info->cub_list.map_matrix[i][j] = 0;
					info->dirX = 0.0;
					info->dirY = 1.0;
					info->planeX = 0.66;
					info->planeY = 0.0;
				}
				else if (info->cub_list.map[i][j] == ' ')
					info->cub_list.map_matrix[i][j] = 3;
				else
				{
					info->cub_list.map_matrix[i][j] = info->cub_list.map[i][j] - '0';
				}
				write(1, ft_itoa(info->cub_list.map_matrix[i][j]), 1);
				j++;
			}
		}
		write(1, "\n", 1);
		i++;
	}

	return (0);
}

int	main(int argc, char *argv[])
{
	t_info info;
	int buffer_size;
	int fd;
	int i;
	char **line;
	char *sin;
	
	if (argc != 2)
	{
		printf("Error\n");
		return (-1);
	}
	buffer_size = 10;
    fd = open(argv[1], O_RDONLY);
	info.cub_list.map_x = 0;
	info.cub_list.map_y = 0;
	info.cub_list.size = 0;
	i = 1;
	while (i > 0)
	{
		i = get_next_line(fd, &line, buffer_size);
		line_check(line, &info);
		// printf("~~~fd: %d line: %s first: %c return: %d~~~\n", fd, line, line[0], i);
		free(line);
	}
	printf("map_x: %d\n", info.cub_list.map_x);
	i = 0;
	while (i < info.cub_list.map_y)
	{
		printf("line: %s\n", info.cub_list.map[i]);
		i++;
	}
	convert_int_matrix(&info);
	info.mlx = mlx_init();
	sin = ft_itoa_hex(info.cub_list.floor.red, "0123456789ABCDEF");
	printf("sin: %s\n", sin);

	// info.posX = 1.0;
	// info.posY = 11.5;
	// info.posX = 3.0;
	// info.posY = 13.0;
	// info.posX = 11.0;
	// info.posY = 26.0;
	// info.dirX = -1.0;
	// info.dirX = 1.0;
	// info.dirY = 0.0;
	// info.planeX = 0.0;
	// info.planeY = 0.66;
	
	if (!(info.buf = (int **)malloc(sizeof(int *) * (info.cub_list.height))))
		return (-1);
	i = 0;
	while (i < info.cub_list.height)
	{
		if (!(info.buf[i] = (int *)malloc(sizeof(int) * (info.cub_list.width))))
			return (-1);
		i++;
	}

	for (int i = 0; i < info.cub_list.height; i++)
	{
		for (int j = 0; j < info.cub_list.width; j++)
		{
			info.buf[i][j] = 0;
		}
	}

	if (!(info.texture = (int **)malloc(sizeof(int *) * 11)))
		return (-1);
	for (int i = 0; i < 11; i++)
	{
		if (!(info.texture[i] = (int *)malloc(sizeof(int) * (texHeight * texWidth))))
			return (-1);
	}
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < texHeight * texWidth; j++)
		{
			info.texture[i][j] = 0;
		}
	}

	load_texture(&info);

	info.moveSpeed = 0.05;
	info.rotSpeed = 0.05;
	
	info.win = mlx_new_window(info.mlx, info.cub_list.width, info.cub_list.height, "mlx");

	info.img.img = mlx_new_image(info.mlx, info.cub_list.width, info.cub_list.height);
	info.img.data = (int *)mlx_get_data_addr(info.img.img, &info.img.bpp, &info.img.size_l, &info.img.endian);

	mlx_loop_hook(info.mlx, &main_loop, &info);
	mlx_hook(info.win, X_EVENT_KEY_PRESS, 1L<<0, &key_press, &info);

	mlx_loop(info.mlx);
}
