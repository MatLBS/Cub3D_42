/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:30:47 by matle-br          #+#    #+#             */
/*   Updated: 2024/10/28 16:21:54 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	size_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	which_fov(t_data *data)
{
	if (data->map->pos_player == 'N')
	{
		data->player->planex = 0.90;
		data->player->planey = 0;
	}
	else if (data->map->pos_player == 'S')
	{
		data->player->planex = -0.90;
		data->player->planey = 0;
	}
	else if (data->map->pos_player == 'E')
	{
		data->player->planex = 0;
		data->player->planey = 0.90;
	}
	else
	{
		data->player->planex = 0;
		data->player->planey = -0.90;
	}
}

void	which_position(t_data *data)
{
	if (data->map->pos_player == 'N')
	{
		data->player->dirx = 0;
		data->player->diry = -1;
	}
	else if (data->map->pos_player == 'S')
	{
		data->player->dirx = 0;
		data->player->diry = 1;
	}
	else if (data->map->pos_player == 'E')
	{
		data->player->dirx = 1;
		data->player->diry = 0;
	}
	else
	{
		data->player->dirx = -1;
		data->player->diry = 0;
	}
	which_fov(data);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	my_mlx_pixel_put_data(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
