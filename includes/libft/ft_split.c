/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:14:10 by matle-br          #+#    #+#             */
/*   Updated: 2024/10/29 12:05:28 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free(char **tab, int k)
{
	int	i;

	i = 0;
	while (i < k)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	counter_word(char const *str, char c)
{
	int	i;
	int	words;
	int	flag;

	i = 0;
	words = 0;
	flag = 0;
	while (str[i] != '\0')
	{
		if (c != str[i] && flag == 0)
		{
			words++;
			flag = 1;
		}
		if (c == str[i] && flag == 1)
			flag = 0;
		i++;
	}
	return (words);
}

char	*ft_strcpy_split(char *dest, char const *src, int size, int j)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**string_size(int number_words, char const *str, char c, char **tab)
{
	int	i;
	int	j;
	int	k;
	int	compteur;

	i = 0;
	k = 0;
	compteur = 0;
	while (compteur++ < number_words)
	{
		while (c == str[i] && str[i] != '\0')
			i++;
		j = i;
		while (c != str[i] && str[i] != '\0')
			i++;
		tab[k] = malloc(sizeof(char) * (i - j) + 1);
		if (tab[k] == NULL)
		{
			ft_free(tab, k);
			return (NULL);
		}
		ft_strcpy_split(tab[k], str, (i - j), j);
		k++;
	}
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	int		number_words;
	char	**tab;

	number_words = counter_word(s, c);
	tab = malloc(sizeof(char *) * (number_words + 1));
	if (tab == NULL)
		return (NULL);
	tab = string_size(number_words, s, c, tab);
	if (tab == NULL)
	{
		free(tab);
		return (NULL);
	}
	tab[number_words] = 0;
	return (tab);
}
