/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:43:04 by amunoz-p          #+#    #+#             */
/*   Updated: 2019/11/22 19:24:24 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int	ft_return_values(int i, int fd, char **memory, char **line)
{
	if (i < 0)
		return (-1);
	else if (i == 0 && s[fd] == NULL)
		return (0);
	else 
		return (ft_separate_line(line, &s[fd]));
}

static	int	ft_separate_line(char **line, char **memory)
{
	char	*aux;
	int	j;

	j = 0;
	while (*memory[j] != '\n' || *memory[j] != '\0')
		j++;
	if (*memory[j] == '\n')
	{
		*line = ft_strsub(*memory, 0, j);
		aux = ft_strdup(&(*memory)[j + 1];
		free(*memory);
		*memory = aux;
		if (*memory[0] == '\0')
		{
			free(*memory);
			*memory = NULL;
		}
	}
	else 
	{
		*line = ft_strdup(*memory);
		free(*memory);
		*memory = NULL;
	}	
}

int			get_next_line(int fd, char **line)
{
	static char **memory;
	int			i;
	int			BUFFER_SIZE;
	char		buffer[BUFFER_SIZE + 1];
	char		*aux;

	if (!fd || !line)
		return (-1);
	i = 0;
	while ((i = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[i] = 0;
		if (!memory)
			memory[fd] = ft_strdup(buffer);
		else
		{
			aux = ft_strjoin(memory[fd], buffer);
			free(memory[fd]);
			memory[fd] = aux;
		}
		if (strchr(memory[fd], '\n'))
			break ;
	}
	return (ft_return_values(i , fd, memory, line));
}
