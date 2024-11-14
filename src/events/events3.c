/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:58:06 by matle-br          #+#    #+#             */
/*   Updated: 2024/11/05 16:03:21 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move_forward(t_data *data)
{
	double	tmpx;
	double	tmpy;

	tmpx = data->player->posx + data->player->dirx * MOVE_SPEED * 6;
	tmpy = data->player->posy + data->player->diry * MOVE_SPEED * 6;
	if (data->map->map[(int)tmpy][(int)tmpx] == 'Z' || \
		data->map->map[(int)(tmpy + 0.15)][(int)tmpx] == 'Z' || \
		data->map->map[(int)(tmpy - 0.15)][(int)tmpx] == 'Z')
	{
		printf("Game over ! You were killed by a Zombie !\n");
		c_handler(data);
	}
	if (data->map->map[(int)tmpy][(int)data->player->posx] != '1' && \
		data->map->map[(int)tmpy][(int)data->player->posx] != 'D')
		data->player->posy += data->player->diry * MOVE_SPEED;
	if (data->map->map[(int)data->player->posy][(int)tmpx] != '1' && \
		data->map->map[(int)data->player->posy][(int)tmpx] != 'D')
		data->player->posx += data->player->dirx * MOVE_SPEED;
}

void	move_backwards(t_data *data)
{
	double	tmpx;
	double	tmpy;

	tmpx = data->player->posx - data->player->dirx * MOVE_SPEED * 6;
	tmpy = data->player->posy - data->player->diry * MOVE_SPEED * 6;
	if (data->map->map[(int)tmpy][(int)tmpx] == 'Z' || \
		data->map->map[(int)(tmpy + 0.15)][(int)tmpx] == 'Z' || \
		data->map->map[(int)(tmpy - 0.15)][(int)tmpx] == 'Z')
	{
		printf("Game over ! You were killed by a Zombie !\n");
		c_handler(data);
	}
	if (data->map->map[(int)tmpy][(int)data->player->posx] != '1' && \
		data->map->map[(int)tmpy][(int)data->player->posx] != 'D')
		data->player->posy -= data->player->diry * MOVE_SPEED;
	if (data->map->map[(int)data->player->posy][(int)tmpx] != '1' && \
		data->map->map[(int)data->player->posy][(int)tmpx] != 'D')
		data->player->posx -= data->player->dirx * MOVE_SPEED;
}

void	move_left(t_data *data)
{
	double	tmpx;
	double	tmpy;

	tmpx = data->player->posx - data->player->planex * MOVE_SPEED * 6;
	tmpy = data->player->posy - data->player->planey * MOVE_SPEED * 6;
	if (data->map->map[(int)tmpy][(int)tmpx] == 'Z' || \
		data->map->map[(int)(tmpy + 0.15)][(int)tmpx] == 'Z' || \
		data->map->map[(int)(tmpy - 0.15)][(int)tmpx] == 'Z')
	{
		printf("Game over ! You were killed by a Zombie !\n");
		c_handler(data);
	}
	if (data->map->map[(int)tmpy][(int)data->player->posx] != '1' && \
		data->map->map[(int)tmpy][(int)data->player->posx] != 'D')
		data->player->posy -= data->player->planey * MOVE_SPEED;
	if (data->map->map[(int)data->player->posy][(int)tmpx] != '1' && \
		data->map->map[(int)data->player->posy][(int)tmpx] != 'D')
		data->player->posx -= data->player->planex * MOVE_SPEED;
}

void	move_right(t_data *data)
{
	double	tmpx;
	double	tmpy;

	tmpx = data->player->posx + data->player->planex * MOVE_SPEED * 6;
	tmpy = data->player->posy + data->player->planey * MOVE_SPEED * 6;
	if (data->map->map[(int)tmpy][(int)tmpx] == 'Z' || \
		data->map->map[(int)(tmpy + 0.15)][(int)tmpx] == 'Z' || \
		data->map->map[(int)(tmpy - 0.15)][(int)tmpx] == 'Z')
	{
		printf("Game over ! You were killed by a Zombie !\n");
		c_handler(data);
	}
	if (data->map->map[(int)tmpy][(int)data->player->posx] != '1' && \
		data->map->map[(int)tmpy][(int)data->player->posx] != 'D')
		data->player->posy += data->player->planey * MOVE_SPEED;
	if (data->map->map[(int)data->player->posy][(int)tmpx] != '1' && \
		data->map->map[(int)data->player->posy][(int)tmpx] != 'D')
		data->player->posx += data->player->planex * MOVE_SPEED;
}

int	release_button(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (button == 1)
		data->keys->mouse_press = 0;
	return (0);
}
