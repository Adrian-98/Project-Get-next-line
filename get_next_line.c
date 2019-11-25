/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:43:04 by amunoz-p          #+#    #+#             */
/*   Updated: 2019/11/25 17:09:08 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int	ft_separate_line(char **line, char **memory, int fd)
{
	char	*aux;
	int		j;

	j = 0;
	while (memory[fd][j] != '\n' && memory[fd][j] != '\0')
		j++;
	if (memory[fd][j] == '\n' && (*line = ft_substr(memory[fd], 0, j)))
	{
		aux = ft_strdup(&memory[fd][j + 1]);
		free(memory[fd]);
		memory[fd] = aux;
		if (memory[fd][0] == '\0')
		{
			free(memory[fd]);
			memory[fd] = NULL;
		}
	}
	else
	{
		*line = ft_strdup(memory[fd]);
		free(memory[fd]);
		memory[fd] = NULL;
		return (0);
	}
	return (1);
}

static	int	ft_return_values(int i, int fd, char **memory, char **line)
{
	if (i < 0)
		return (-1);
	else if (i == 0 && memory[fd] == NULL)
	{
		*line = ft_strdup("");
		memory[fd] = NULL;
		return (0);
	}
	else
		return (ft_separate_line(line, memory, fd));
}

int			get_next_line(int fd, char **line)
{
	static char *memory[4096];
	int			i;
	char		buffer[BUFFER_SIZE + 1];
	char		*aux;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
	{
		memory[fd] = NULL;
		return (-1);
	}
	while ((i = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[i] = '\0';
		if (memory[fd] == NULL)
			memory[fd] = ft_strdup(buffer);
		else
		{
			aux = ft_strjoin(memory[fd], buffer);
			free(memory[fd]);
			memory[fd] = aux;
		}
		if (ft_strchr(memory[fd], '\n'))
			break ;
	}
	return (ft_return_values(i, fd, memory, line));
}
