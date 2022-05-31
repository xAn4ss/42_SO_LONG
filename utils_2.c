/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoukhart <aoukhart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 01:44:18 by aoukhart          #+#    #+#             */
/*   Updated: 2022/05/30 21:05:45 by aoukhart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(const char *s)
{
	unsigned long	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;
	size_t	i;

	i = 0;
	str = malloc(count * size);
	if (!str)
		return (NULL);
	while (i < count * size)
	{
		*(unsigned char *)(str + i) = 0;
		i++;
	}
	return (str);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		*(unsigned char *)(b + i) = (unsigned char)c;
		i++;
	}
	return (b);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*cat;
	size_t	i;
	size_t	j;

	i = -1;
	if (!s1 || !s2)
		return (NULL);
	cat = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, 1);
	if (!cat)
		return (NULL);
	while (s1[++i])
		cat[i] = s1[i];
	free(s1);
	j = i;
	i = 0;
	while (s2[i])
		cat[j++] = s2[i++];
	return (cat);
}
