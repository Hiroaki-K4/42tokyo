/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:27:46 by hkubo             #+#    #+#             */
/*   Updated: 2021/05/26 17:28:56 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void draw_sprite(t_info *info)
{
	int		spriteOrder[info->cub_list.num_sprites];
	double	spriteDistance[info->cub_list.num_sprites];
	
	for(int i = 0; i < info->cub_list.num_sprites; i++)
	{
		spriteOrder[i] = i;
		spriteDistance[i] = ((info->posX - info->cub_list.sprites[i].x) * (info->posX - info->cub_list.sprites[i].x) + (info->posY - info->cub_list.sprites[i].y) * (info->posY - info->cub_list.sprites[i].y)); //sqrt not taken, unneeded
	}
	sortSprites(spriteOrder, spriteDistance, info->cub_list.num_sprites);
	//after sorting the sprites, do the projection and draw them
	for(int i = 0; i < info->cub_list.num_sprites; i++)
	{
		//translate sprite position to relative to camera
		// double spriteX = sprite[spriteOrder[i]].x - info->posX;
		double spriteX = info->cub_list.sprites[spriteOrder[i]].x + 0.5 - info->posX;
		// double spriteY = sprite[spriteOrder[i]].y - info->posY;
		double spriteY = info->cub_list.sprites[spriteOrder[i]].y + 0.5 - info->posY;

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
		if (drawStartY < 0)
			drawStartY = 0;
		int drawEndY = spriteHeight / 2 + info->cub_list.height / 2 + vMoveScreen;
		if (drawEndY >= info->cub_list.height)
			drawEndY = info->cub_list.height - 1;

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
				// int color = info->texture[sprite[spriteOrder[i]].texture][texWidth * texY + texX]; //get current color from the texture
				int color = info->texture[info->cub_list.sprites[spriteOrder[i]].texture][texWidth * texY + texX]; //get current color from the texture
				if((color & 0x00FFFFFF) != 0)
					info->buf[y][stripe] = color; //paint pixel if it isn't black, black is the invisible color
			}
		}
	}
}