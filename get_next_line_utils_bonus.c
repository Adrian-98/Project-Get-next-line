/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:52:28 by amunoz-p          #+#    #+#             */
/*   Updated: 2019/11/23 21:31:41 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char			*ft_substr(char *s, int start, int len)
{
	char				*puntero;
	int					i;

	if (s == NULL)
		return (NULL);
	if (!(puntero = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		puntero[i] = 0;
		i++;
	}
	if (i > start)
	{
		i = 0;
		while (len-- > 0)
		{
			puntero[i] = s[start];
			i++;
			start++;
		}
	}
	puntero[i] = '\0';
	return (puntero);
}

int				ft_strlen(const char *str)
{
	int k;

	k = 0;
	while (*str != '\0')
	{
		k++;
		str++;
	}
	return (k);
}

char			*ft_strdup(const char *s1)
{
	char	*p;
	int		i;

	if (!s1)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
		i++;
	p = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	if (p == NULL)
		return (0);
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	l;
	size_t	j;
	char	*str;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	l = ft_strlen(s1) + ft_strlen(s2);
	str = (char*)malloc(sizeof(char*) * (l + 1));
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = 0;
	return (str);
}

char			*ft_strchr(const char *s, int c)
{
	char	a;
	int		i;

	i = 0;
	a = c;
	while (s[i] != '\0')
	{
		if (s[i] == a)
			return (&((char*)s)[i]);
		i++;
	}
	if (c == 0)
		return ((char*)s + i);
	return (0);
}
