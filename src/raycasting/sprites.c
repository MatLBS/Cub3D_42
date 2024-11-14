/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:08:30 by matle-br          #+#    #+#             */
/*   Updated: 2024/11/07 15:37:49 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	sort_sprites(t_data *data, int i)
{
	int			j;
	t_sprites	temp;

	while (++i < data->num_sprites)
	{
		data->sprites[i].spriteorder = i;
		data->sprites[i].spritedistance = (pow(data->player->posx - \
			data->sprites[i].posx, 2) + pow(data->player->posy - \
			data->sprites[i].posy, 2));
	}
	i = -1;
	while (++i < data->num_sprites)
	{
		j = -1;
		while (++j < data->num_sprites - 1)
		{
			if (data->sprites[j].spritedistance < \
				data->sprites[j + 1].spritedistance)
			{
				temp = data->sprites[j];
				data->sprites[j] = data->sprites[j + 1];
				data->sprites[j + 1] = temp;
			}
		}
	}
}

void	create_sprites4(t_data *data, int nb, int y)
{
	data->sprites->texy = (int)((y - data->sprites->drawstarty) \
		* data->tab_img[nb].height / data->sprites->spriteheight);
	data->wall->color = get_pixel_color(&data->tab_img[nb], \
		data->sprites->texx, data->sprites->texy, data);
	if (data->wall->color != 0)
		my_mlx_pixel_put_data(data, data->sprites->stripe, \
			y, data->wall->color);
}

void	create_sprites3(t_data *data, int nb, int y)
{
	if (data->sprites->drawendx >= data->width)
		data->sprites->drawendx = data->width - 1;
	data->sprites->stripe = data->sprites->drawstartx - 1;
	while (++data->sprites->stripe < data->sprites->drawendx)
	{
		if (data->sprites->transformy > 0 && data->sprites->stripe > 0 && \
			data->sprites->stripe < data->width && \
			data->sprites->transformy < data->zbuffer[data->sprites->stripe])
		{
			y = data->sprites->drawstarty - 1;
			while (++y < data->sprites->drawendy)
			{
				data->sprites->texx = (int)((data->sprites->stripe - \
					(-data->sprites->spritewidth / 2 + \
					data->sprites->spritescreenx)) * data->tab_img[nb].width / \
					data->sprites->spritewidth);
				create_sprites4(data, nb, y);
			}
		}
	}
}

void	create_sprites2(t_data *data, int nb)
{
	data->sprites->transformy = data->sprites->invdet * \
		(-data->player->planey * data->sprites->spritex + \
		data->player->planex * data->sprites->spritey);
	data->sprites->spritescreenx = (int)((data->width / 2) \
			* (1 + data->sprites->transformx / data->sprites->transformy));
	data->sprites->spriteheight = abs((int)(data->height / \
		data->sprites->transformy));
	data->sprites->drawstarty = -data->sprites->spriteheight / 2 \
		+ data->height / 2;
	if (data->sprites->drawstarty < 0)
		data->sprites->drawstarty = 0;
	data->sprites->drawendy = data->sprites->spriteheight / 2 \
		+ data->height / 2;
	if (data->sprites->drawendy >= data->height)
		data->sprites->drawendy = data->height - 1;
	data->sprites->spritewidth = abs((int)(data->height / \
		data->sprites->transformy));
	data->sprites->drawstartx = -data->sprites->spritewidth / 2 \
		+ data->sprites->spritescreenx;
	if (data->sprites->drawstartx < 0)
		data->sprites->drawstartx = 0;
	data->sprites->drawendx = data->sprites->spritewidth / 2 \
		+ data->sprites->spritescreenx;
	create_sprites3(data, nb, 0);
}

void	create_sprites(t_data *data, int x)
{
	static int	nb = FRAME_1;
	static int	frame_counter = 0;

	if (nb == FRAME_6 + 1)
		nb = FRAME_1;
	sort_sprites(data, -1);
	while (++x < data->num_sprites)
	{
		data->sprites->spritex = data->sprites[x].posx - data->player->posx;
		data->sprites->spritey = data->sprites[x].posy - data->player->posy;
		data->sprites->invdet = 1.0 / (data->player->planex * \
			data->player->diry - data->player->dirx * data->player->planey);
		data->sprites->transformx = data->sprites->invdet * \
			(data->player->diry * data->sprites->spritex - \
			data->player->dirx * data->sprites->spritey);
		create_sprites2(data, nb);
	}
	frame_counter++;
	if (frame_counter >= 15)
	{
		frame_counter = 0;
		nb++;
	}
}
