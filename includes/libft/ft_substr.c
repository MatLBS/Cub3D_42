/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:52:07 by matle-br          #+#    #+#             */
/*   Updated: 2024/05/21 15:06:58 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*check(void)
{
	char	*new_str;

	new_str = malloc(sizeof(char) * 1);
	if (new_str == NULL)
		return (NULL);
	new_str[0] = '\0';
	return (new_str);
}

char	*fill_in(size_t len, char const *s, unsigned int start)
{
	char	*new_str;
	size_t	i;

	new_str = malloc(sizeof(char) * len + 1);
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while ((i < len) && (s[start] != '\0'))
	{
		new_str[i] = s[start];
		i++;
		start++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*new_str;

	s_len = ft_strlen(s);
	if (!s)
		return (NULL);
	if (start > s_len)
	{
		new_str = check();
		return (new_str);
	}
	if (len > (s_len - start))
		len = s_len - start;
	new_str = fill_in(len, s, start);
	return (new_str);
}
