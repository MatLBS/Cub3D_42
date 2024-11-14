/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:08:18 by matle-br          #+#    #+#             */
/*   Updated: 2024/10/30 17:33:50 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_isspace(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\r'
		|| str[i] == '\f' || str[i] == '\v'
		|| str[i] == '\n' || str[i] == '\t')
	{
		i++;
	}
	return (i);
}

char	*check_xpm(t_data *data, int i)
{
	char	*str2;
	char	*new_str;

	i += 2;
	check_no_xpm(data, i);
	while (!ft_isalnum(data->str[i]))
		i++;
	new_str = malloc(sizeof(char) * (ft_strlen(data->str) - i + 1));
	if (!new_str)
		return (ft_free_data(data), get_next_line(data->fd, 1), NULL);
	ft_strcpy_cub(new_str, data->str, (ft_strlen(data->str) - i), i);
	if (check_whitespace(new_str) == 0)
	{
		printf("Bad xpm input, found a whitespace.\n");
		get_next_line(data->fd, 1);
		return (free(new_str), ft_free_data(data), exit(EXIT_FAILURE), NULL);
	}
	str2 = ft_strrchr(data->str, '.');
	if (ft_strncmp(str2, ".xpm", 4) != 0)
		return (printf("No .xpm at end of file.\n"), \
			free(new_str), ft_free_data(data), \
			get_next_line(data->fd, 1), exit(EXIT_FAILURE), NULL);
	data->map->nb_params += 1;
	return (new_str);
}

int	check_whitespace(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			return (0);
		i++;
	}
	return (1);
}

int	check_rgb_suite(char **tab, t_data *data, char *new_str, int i)
{
	int	nb1;
	int	nb2;
	int	nb3;

	while (tab[++i])
	{
		if (ft_atoi(tab[i]) > 255 || ft_atoi(tab[i]) < 0)
		{
			printf("Invalid RGB input.\n\
RGB must contain numbers between 0 and 255.\n");
			free(new_str);
			ft_free_data(data);
			ft_free_cub(tab);
			return (get_next_line(data->fd, 1), exit(EXIT_FAILURE), 0);
		}
	}
	nb1 = ft_atoi(tab[0]);
	nb2 = ft_atoi(tab[1]);
	nb3 = ft_atoi(tab[2]);
	ft_free_cub(tab);
	return ((nb1 << 16) + (nb2 << 8) + nb3);
}

int	check_rgb(t_data *data, int i)
{
	char	**tab;
	char	*new_str;
	int		nb;

	i += 1;
	check_no_rgb(data, i);
	while (!ft_isalnum(data->str[i]))
		i++;
	new_str = malloc(sizeof(char) * (ft_strlen(data->str) - i + 1));
	if (!new_str)
		return (ft_free_data(data), 0);
	ft_strcpy_cub(new_str, data->str, (ft_strlen(data->str) - i), i);
	if (check_whitespace(new_str) == 0 || check_number(new_str) == 0)
	{
		printf("Error: Bad rgb input.\n");
		return (get_next_line(data->fd, 1), free(new_str), \
			ft_free_data(data), exit(EXIT_FAILURE), 0);
	}
	tab = ft_split(new_str, ',');
	if (!tab)
		return (get_next_line(data->fd, 1), ft_free_data(data), 1);
	nb = check_rgb_suite(tab, data, new_str, -1);
	free(new_str);
	data->map->nb_params += 1;
	return (nb);
}
