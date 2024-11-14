/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 09:36:17 by matle-br          #+#    #+#             */
/*   Updated: 2024/11/13 14:31:13 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

long	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
	{
		printf("Error with gettimeofday");
		return (-1);
	}
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	init_imgs(t_img *tab_img)
{
	int	i;

	i = 0;
	while (i < 18)
	{
		tab_img[i].img = NULL;
		tab_img[i].addr = NULL;
		tab_img[i].bits_per_pixel = 0;
		tab_img[i].line_length = 0;
		tab_img[i].endian = 0;
		tab_img[i].width = 0;
		tab_img[i].height = 0;
		i++;
	}
}

t_keys	*init_keys(t_data *data)
{
	t_keys	*keys;

	keys = malloc(sizeof(t_keys));
	if (!keys)
		return (printf("Error while allocating keys.\n"), \
			ft_free_data(data), exit(EXIT_FAILURE), NULL);
	keys->key_a = 0;
	keys->key_d = 0;
	keys->key_s = 0;
	keys->key_w = 0;
	keys->left_arrow = 0;
	keys->right_arrow = 0;
	keys->mouse_press = 0;
	return (keys);
}

void	init_data(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->img = NULL;
	data->addr = NULL;
	data->str = NULL;
	data->width = 0;
	data->height = 0;
	data->mouse = 0;
	data->fd = -1;
	data->zbuffer = NULL;
	data->num_sprites = 0;
	data->first_action = get_time();
	data->action_mouse = get_time();
	data->hit = 0;
	data->pid_music = -1;
	data->map = init_map();
	data->player = init_player(data);
	data->wall = init_wall(data);
	data->keys = init_keys(data);
	data->sprites = NULL;
	init_imgs(data->tab_img);
}

void	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (ft_free_data(data), exit(EXIT_FAILURE));
	mlx_get_screen_size(data->mlx, &data->width, &data->height);
	data->win = mlx_new_window(data->mlx, data->width, data->height, "Cub3D");
	if (!data->win)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		return (ft_free_data(data), exit(EXIT_FAILURE));
	}
	data->img = mlx_new_image(data->mlx, data->width, data->height);
	if (!data->img)
		c_handler(data);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
					&data->line_length, &data->endian);
	if (!data->addr)
	{
		mlx_destroy_image(data->mlx, data->img);
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		ft_free_data(data);
		exit(EXIT_FAILURE);
	}
}
