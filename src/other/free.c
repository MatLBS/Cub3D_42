/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:55:55 by matle-br          #+#    #+#             */
/*   Updated: 2024/11/13 14:30:53 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_free_cub(char **tab)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	if (!tab)
		return ;
	while (tab[k])
		k++;
	while (i < k)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_free_images_2(t_data *data)
{
	if (data->tab_img[FRAME_2].img)
		mlx_destroy_image(data->mlx, data->tab_img[FRAME_2].img);
	if (data->tab_img[FRAME_3].img)
		mlx_destroy_image(data->mlx, data->tab_img[FRAME_3].img);
	if (data->tab_img[FRAME_4].img)
		mlx_destroy_image(data->mlx, data->tab_img[FRAME_4].img);
	if (data->tab_img[FRAME_5].img)
		mlx_destroy_image(data->mlx, data->tab_img[FRAME_5].img);
	if (data->tab_img[FRAME_6].img)
		mlx_destroy_image(data->mlx, data->tab_img[FRAME_6].img);
	if (data->tab_img[FRAME_K_1].img)
		mlx_destroy_image(data->mlx, data->tab_img[FRAME_K_1].img);
	if (data->tab_img[FRAME_K_2].img)
		mlx_destroy_image(data->mlx, data->tab_img[FRAME_K_2].img);
	if (data->tab_img[FRAME_K_3].img)
		mlx_destroy_image(data->mlx, data->tab_img[FRAME_K_3].img);
	if (data->tab_img[FRAME_K_4].img)
		mlx_destroy_image(data->mlx, data->tab_img[FRAME_K_4].img);
	if (data->tab_img[FRAME_K_5].img)
		mlx_destroy_image(data->mlx, data->tab_img[FRAME_K_5].img);
}

void	ft_free_images(t_data *data)
{
	if (data->tab_img[BACKGROUND].img)
		mlx_destroy_image(data->mlx, data->tab_img[BACKGROUND].img);
	if (data->tab_img[NORTH].img)
		mlx_destroy_image(data->mlx, data->tab_img[NORTH].img);
	if (data->tab_img[SOUTH].img)
		mlx_destroy_image(data->mlx, data->tab_img[SOUTH].img);
	if (data->tab_img[EAST].img)
		mlx_destroy_image(data->mlx, data->tab_img[EAST].img);
	if (data->tab_img[WEST].img)
		mlx_destroy_image(data->mlx, data->tab_img[WEST].img);
	if (data->tab_img[DOOR].img)
		mlx_destroy_image(data->mlx, data->tab_img[DOOR].img);
	if (data->tab_img[DOOR_1].img)
		mlx_destroy_image(data->mlx, data->tab_img[DOOR_1].img);
	if (data->tab_img[FRAME_1].img)
		mlx_destroy_image(data->mlx, data->tab_img[FRAME_1].img);
	ft_free_images_2(data);
}

void	ft_free_data_2(t_data *data)
{
	if (data->player)
		free(data->player);
	if (data->wall)
		free(data->wall);
	if (data->keys)
		free(data->keys);
	if (data->str)
		free(data->str);
	if (data->img)
		ft_free_images(data);
	if (data->sprites)
		free(data->sprites);
	if (data->zbuffer)
		free(data->zbuffer);
	if (data->pid_music >= 0)
		kill(data->pid_music, SIGKILL);
}

void	ft_free_data(t_data *data)
{
	if (data->map->no)
		free(data->map->no);
	if (data->map->so)
		free(data->map->so);
	if (data->map->we)
		free(data->map->we);
	if (data->map->ea)
		free(data->map->ea);
	if (data->map->map)
		ft_free_cub(data->map->map);
	if (data->map->cpy_map)
		ft_free_cub(data->map->cpy_map);
	if (data->map)
		free(data->map);
	ft_free_data_2(data);
	if (data->fd > 0)
		close(data->fd);
}
