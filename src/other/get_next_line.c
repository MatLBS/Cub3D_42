/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 09:07:18 by matle-br          #+#    #+#             */
/*   Updated: 2024/10/18 11:20:10 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static char	*ft_free(char *str, char *str2)
{
	free(str);
	if (str2 == NULL)
		return (NULL);
	free(str2);
	return (NULL);
}

char	*fill_stash(int fd, char *stash)
{
	char	*buff;
	char	*tmp;
	int		bytes_read;

	bytes_read = 1;
	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (buff == NULL)
		return (ft_free(stash, 0));
	while (bytes_read)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read < 0)
			return (ft_free(stash, buff));
		buff[bytes_read] = '\0';
		tmp = ft_strjoin(stash, buff);
		free(stash);
		stash = tmp;
		if (stash == NULL)
			return (ft_free(buff, 0));
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buff);
	return (stash);
}

char	*fill_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	if (stash[i] == '\0')
		return (NULL);
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (line == NULL)
		return (NULL);
	line[i--] = '\0';
	while (i >= 0)
	{
		line[i] = stash[i];
		i--;
	}
	return (line);
}

char	*clean_stash(char *stash)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\0' || (stash[i] == '\n' && stash[i + 1] == '\0'))
		return (free(stash), NULL);
	tmp = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (tmp == NULL)
		return (ft_free(stash, 0));
	i++;
	j = 0;
	while (stash[i] != '\0')
		tmp[j++] = stash[i++];
	tmp[j] = '\0';
	free(stash);
	return (tmp);
}

char	*get_next_line(int fd, int flag)
{
	char		*line;
	static char	*stash;

	if (flag == 1)
		return (free(stash), NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (stash == NULL)
		stash = ft_calloc(1, sizeof(char));
	if (stash == NULL)
		return (NULL);
	stash = fill_stash(fd, stash);
	if (stash == NULL)
		return (NULL);
	line = fill_line(stash);
	if (line == NULL)
		return (free(stash), stash = 0, NULL);
	stash = clean_stash(stash);
	return (line);
}
