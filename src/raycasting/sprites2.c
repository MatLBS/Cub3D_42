/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:23:17 by matle-br          #+#    #+#             */
/*   Updated: 2024/11/07 08:39:19 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	move_knife_2(t_data *data, int nb)
{
	int			tmpx;
	int			tmpy;
	static int	frame_counter = 0;

	tmpx = data->player->posx + data->player->dirx;
	tmpy = data->player->posy + data->player->diry;
	if (data->map->map[tmpy][tmpx] == 'Z' && nb == FRAME_K_3)
	{
		data->map->map[tmpy][tmpx] = '0';
		data->num_sprites -= 1;
	}
	frame_counter++;
	if (frame_counter >= 3)
	{
		frame_counter = 0;
		nb++;
	}
	return (nb);
}

int	move_knife(t_data *data, int x, int y)
{
	static int	nb = FRAME_K_1;
	int			posx;
	int			posy;

	if (nb == FRAME_K_5 + 1)
		nb = FRAME_K_1;
	posy = data->width / 5;
	y = -1;
	while (++y < data->tab_img[nb].height)
	{
		posx = data->width / 5;
		x = -1;
		while (++x < data->tab_img[nb].width)
		{
			data->wall->color = get_pixel_color(&data->tab_img[nb], \
			x, y, data);
			if (data->wall->color != 0)
				my_mlx_pixel_put_data(data, posx, \
				posy, data->wall->color);
			posx++;
		}
		posy++;
	}
	nb = move_knife_2(data, nb);
	return (0);
}
