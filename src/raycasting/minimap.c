/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:17:16 by matle-br          #+#    #+#             */
/*   Updated: 2024/11/13 14:32:50 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	print_pixel(t_data *data, int x, int y, int color)
{
	my_mlx_pixel_put_data(data, x + data->width / 16, \
		y + data->height / 1.4, color);
}

void	draw_player_direction(t_data *data, int i)
{
	double	new_x;
	double	new_y;
	double	new_posx;
	double	new_posy;

	new_posx = WIDTH_MINIMAP / 2;
	new_posy = HEIGHT_MINIMAP / 2;
	while (i < 15)
	{
		new_x = new_posx + data->player->dirx * i;
		new_y = new_posy + data->player->diry * i;
		print_pixel(data, new_x, new_y, 0xFF0000);
		print_pixel(data, new_x, new_y, 0xFF0000);
		i++;
	}
}

void	find_pixel(t_data *data, int x, int y)
{
	double	new_x;
	double	new_y;
	double	new_posx;
	double	new_posy;

	new_posx = WIDTH_MINIMAP / 2;
	new_posy = HEIGHT_MINIMAP / 2;
	new_x = (x - new_posx) / SIZE_SQUARE + data->player->posx;
	new_y = (y - new_posy) / SIZE_SQUARE + data->player->posy;
	if (new_x < 0 || new_y < 0 || new_y >= size_tab(data->map->map) || \
	new_x > (int)ft_strlen(data->map->map[(int)new_y]))
		print_pixel(data, x, y, 16777215);
	else if ((x >= 145 && x <= 155) && (y >= 95 && y <= 105))
		print_pixel(data, x, y, 4266955);
	else if (data->map->map[(int)new_y][(int)new_x] == '1')
		print_pixel(data, x, y, 13882323);
	else if (data->map->map[(int)new_y][(int)new_x] == 'D' || \
		data->map->cpy_map[(int)new_y][(int)new_x] == 'D')
		print_pixel(data, x, y, 16761035);
	else
		print_pixel(data, x, y, 16777215);
}

void	create_minimap(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT_MINIMAP)
	{
		x = -1;
		while (++x < WIDTH_MINIMAP)
			find_pixel(data, x, y);
	}
	draw_player_direction(data, 1);
}
