/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:50:57 by matle-br          #+#    #+#             */
/*   Updated: 2024/10/27 17:01:53 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_wall	*init_wall(t_data *data)
{
	t_wall	*wall;

	wall = malloc(sizeof(t_map));
	if (!wall)
		return (printf("Error while allocating wall.\n"), \
			ft_free_data(data), exit(EXIT_FAILURE), NULL);
	wall->perpwalldist = 0;
	wall->lineheight = 0;
	wall->drawend = 0;
	wall->drawstart = 0;
	wall->color = 0;
	wall->width_xpm = 0;
	wall->height_xpm = 0;
	wall->face = -1;
	wall->hit_door = -1;
	wall->hit_zombie = 0;
	return (wall);
}

t_map	*init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (printf("Error while allocating map.\n"), \
			exit(EXIT_FAILURE), NULL);
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	map->map = NULL;
	map->cpy_map = NULL;
	map->pos_player = 0;
	map->player = 0;
	map->f = 0;
	map->c = 0;
	map->nb_params = 0;
	return (map);
}

void	init_player_2(t_player *player)
{
	player->planex = 0;
	player->planey = 0;
	player->camerax = 0;
	player->raydirx = 0;
	player->raydiry = 0;
	player->texx = 0;
	player->texy = 0;
	player->wallx = 0;
	player->texpos = 0;
	player->step = 0;
}

t_player	*init_player(t_data *data)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (printf("Error while allocating player.\n"), \
			ft_free_data(data), exit(EXIT_FAILURE), NULL);
	player->posx = 0;
	player->posy = 0;
	player->dirx = 0;
	player->posy = 0;
	player->mapx = 0;
	player->mapy = 0;
	player->stepx = 0;
	player->stepy = 0;
	player->sidedistx = 0;
	player->sidedisty = 0;
	player->deltadistx = 0;
	player->deltadisty = 0;
	init_player_2(player);
	return (player);
}
