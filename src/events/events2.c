/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:48:58 by matle-br          #+#    #+#             */
/*   Updated: 2024/11/05 16:01:53 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	turn_left(t_data *data, double rotation_speed)
{
	double	olddirx;
	double	oldplanex;

	olddirx = data->player->dirx;
	data->player->dirx = data->player->dirx * cos(-rotation_speed) - \
	data->player->diry * sin(-rotation_speed);
	data->player->diry = olddirx * sin(-rotation_speed) + \
	data->player->diry * cos(-rotation_speed);
	oldplanex = data->player->planex;
	data->player->planex = data->player->planex * cos(-rotation_speed) - \
	data->player->planey * sin(-rotation_speed);
	data->player->planey = oldplanex * sin(-rotation_speed) + \
	data->player->planey * cos(-rotation_speed);
}

void	turn_right(t_data *data, double rotation_speed)
{
	double	olddirx;
	double	oldplanex;
	int		mult;

	mult = 1;
	olddirx = data->player->dirx;
	data->player->dirx = data->player->dirx * cos(rotation_speed) - \
		data->player->diry * sin(rotation_speed);
	data->player->diry = olddirx * sin(rotation_speed) + \
		data->player->diry * cos(rotation_speed);
	oldplanex = data->player->planex;
	data->player->planex = data->player->planex * cos(rotation_speed) - \
		data->player->planey * sin(rotation_speed);
	data->player->planey = oldplanex * sin(rotation_speed) + \
		data->player->planey * cos(rotation_speed);
}

int	c_handler(t_data *data)
{
	ft_free_data(data);
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(EXIT_FAILURE);
	return (0);
}

int	handle_mouse(int x, int y, t_data *data)
{
	int		centerx;
	int		centery;
	int		deltax;
	double	rotation_speed;
	long	nb;

	(void)y;
	if (data->mouse == 0)
		return (0);
	centerx = data->width / 2;
	centery = data->height / 2;
	deltax = x - centerx;
	rotation_speed = TURN_SPEED * (deltax / MOUSE_SENSI);
	if (deltax <= 0)
		turn_left(data, fabs(rotation_speed));
	else
		turn_right(data, fabs(rotation_speed));
	nb = get_time();
	if (nb - data->action_mouse > 5)
	{
		data->action_mouse = get_time();
		mlx_mouse_move(data->mlx, data->win, centerx, centery);
	}
	return (0);
}

int	handle_button(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (button == 1)
		data->keys->mouse_press = 1;
	return (0);
}
