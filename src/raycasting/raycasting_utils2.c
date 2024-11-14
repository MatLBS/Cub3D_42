/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:55:31 by matle-br          #+#    #+#             */
/*   Updated: 2024/11/13 14:32:17 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

unsigned long	get_pixel_color(t_img *img, \
	int pixelX, int pixelY, t_data *data)
{
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
		&img->line_length, &img->endian);
	if (!img->addr)
	{
		ft_free_data(data);
		c_handler(data);
	}
	return (*(unsigned long *)((img->addr + (pixelY * img->line_length) + \
		(pixelX * img->bits_per_pixel / 8))));
}

void	get_texture_color_suite(t_data *data, int pixelX, int y)
{
	data->player->wallx -= floor(data->player->wallx);
	data->player->texx = (int)(data->player->wallx * \
		(double)(data->tab_img[data->wall->face].width));
	if (data->wall->side == 0 && data->player->raydirx < 0)
		data->player->texx = data->tab_img[data->wall->face].width \
			- data->player->texx - 1;
	if (data->wall->side == 1 && data->player->raydiry > 0)
		data->player->texx = data->tab_img[data->wall->face].width \
			- data->player->texx - 1;
	data->player->step = 1.0 * data->tab_img[data->wall->face].height \
		/ data->wall->lineheight;
	data->player->texpos = (data->wall->drawstart - data->height / \
		2 + data->wall->lineheight / 2) * data->player->step;
	while (y < data->wall->drawend)
	{
		data->player->texy = (int)data->player->texpos % \
			(data->tab_img[data->wall->face].height - 1);
		data->player->texpos += data->player->step;
		data->wall->color = get_pixel_color(&data->tab_img[data->wall->face], \
			data->player->texx, data->player->texy, data);
		if (data->wall->color != 0)
			my_mlx_pixel_put_data(data, pixelX, y, data->wall->color);
		y++;
	}
}

void	get_texture_color(t_data *data, int pixelX, int y)
{
	y = data->wall->drawstart;
	if (data->wall->hit_door == 1)
		data->wall->face = DOOR;
	else if (data->wall->side == 0)
	{
		if (data->player->raydirx > 0)
			data->wall->face = EAST;
		else
			data->wall->face = WEST;
	}
	else
	{
		if (data->player->raydiry > 0)
			data->wall->face = SOUTH;
		else
			data->wall->face = NORTH;
	}
	if (data->wall->side == 0)
		data->player->wallx = data->player->posy + \
			(data->wall->perpwalldist * data->player->raydiry);
	else
		data->player->wallx = data->player->posx + \
			(data->wall->perpwalldist * data->player->raydirx);
	get_texture_color_suite(data, pixelX, y);
}

void	display_wall(t_data *data, int x)
{
	data->wall->lineheight = (int)(data->height / data->wall->perpwalldist);
	data->wall->drawstart = ((data->wall->lineheight * -1) \
		/ 2 + data->height / 2);
	if (data->wall->drawstart < 0)
		data->wall->drawstart = 0;
	data->wall->drawend = data->wall->lineheight / 2 + data->height / 2;
	if (data->wall->drawend >= data->height)
		data->wall->drawend = data->height - 1;
	get_texture_color(data, x, 0);
}
