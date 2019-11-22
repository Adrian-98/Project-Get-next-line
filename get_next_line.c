/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:43:04 by amunoz-p          #+#    #+#             */
/*   Updated: 2019/11/22 19:08:12 by amunoz-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int	ft_retunr_values(int i)
{
	if (i == 0)
		return (0);
	else 
		return (1);
}

static	int	ft_separate_line(char **line, char **memory, int i)
{
	char *aux;
	int j;
	
	j = 0;
	if (i < 0)
		return(-1);
	while (memory == '\n' || memory != '\0')
	{
		*line = *memory;
		line++;
		memory++;
	}
	while (memory != '\0')
	{
		aux[j++] = *memory++;
		j++; 
	}
	free(memory);
	memory = aux;
	return (ft_return_values(i));
}

	
int		get_next_line(int fd, char **line)
{
	static char **memory;
	int 		i;
	int			BUFFER_SIZE;
	char		*buffer[BUFFER_SIZE + 1];
	char		*aux;
	
	if (!fd || !line)
		return (-1);
	i = 0;
	while ( i = read(fd,  buffer, BUFFER_SIZE) > 0)
	{
		buffer[i] = '\0';
		if (!memory)
			memory[fd] = ft_strdup(buffer); 
		else
		{
			aux = ft_strjoin(memory[fd], buffer);
			free(memory[fd]);
			memory[fd] = aux;
		}
		if (strchr(memory[fd], '\n'))
			break;
	}
	return (ft_separate_line(line, memory[fd], i));
}
