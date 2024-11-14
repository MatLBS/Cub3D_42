/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:08:20 by matle-br          #+#    #+#             */
/*   Updated: 2024/10/30 17:11:13 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_no_rgb(t_data *data, int start)
{
	int	i;

	i = start;
	while (!ft_isalnum(data->str[i]))
	{
		if (data->str[i] == '\0')
		{
			printf("No rgb input.\n");
			ft_free_data(data);
			get_next_line(data->fd, 1);
			return (exit(EXIT_FAILURE), 1);
		}
		i++;
	}
	return (i);
}

int	check_no_xpm(t_data *data, int start)
{
	int	i;

	i = start;
	while (!ft_isalnum(data->str[i]))
	{
		if (data->str[i] == '\0')
		{
			printf("No xpm input.\n");
			ft_free_data(data);
			get_next_line(data->fd, 1);
			return (exit(EXIT_FAILURE), 1);
		}
		i++;
	}
	return (i);
}

static void	fill_map_line(t_data *data, int nb, int len, int i)
{
	char	*new_line;

	new_line = malloc(sizeof(char) * nb + 1);
	ft_strcpy(new_line, data->map->map[i]);
	while (len < nb)
	{
		new_line[len] = ' ';
		len++;
	}
	new_line[nb] = '\0';
	free(data->map->map[i]);
	data->map->map[i] = new_line;
}

static void	check_no_map(t_data *data)
{
	int	i;

	i = 0;
	if (data->map->map == NULL)
	{
		printf("Error : There is no map.\n");
		return (ft_free_data(data), exit(EXIT_FAILURE));
	}
	while (data->map->map[i][0] == '\0')
	{
		i++;
		if (data->map->map[i] == NULL)
		{
			printf("Error : There is no map.\n");
			return (ft_free_data(data), exit(EXIT_FAILURE));
		}
	}
}

void	fill_map(t_data *data, int i, int nb, int len)
{
	check_no_map(data);
	while (data->map->map[++i])
	{
		if ((int)(ft_strlen(data->map->map[i])) > nb)
			nb = ft_strlen(data->map->map[i]);
	}
	i = 0;
	while (data->map->map[i][0] == '\0')
		i++;
	while (data->map->map[i])
	{
		len = ft_strlen(data->map->map[i]);
		if (len < nb)
			fill_map_line(data, nb, len, i);
		i++;
	}
}
