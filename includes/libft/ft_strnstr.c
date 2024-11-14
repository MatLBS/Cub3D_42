/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matle-br <matle-br@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:41:46 by matle-br          #+#    #+#             */
/*   Updated: 2024/05/21 11:18:33 by matle-br         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == '\0')
		return ((char *) big);
	if (len == 0)
		return (0);
	while (big[i])
	{
		j = 0;
		while ((big[i + j] == little[j]) && (i + j) < len)
		{
			if (little[j + 1] == '\0')
				return ((char *)&big[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
/*
int main(void)
{
	size_t nb;

	nb = 1;
	printf("%s\n", ft_strnstr("this is the way", "the", nb));
}*/
