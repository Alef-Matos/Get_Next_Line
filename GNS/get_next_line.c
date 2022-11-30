/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almatos <almatos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:27:07 by almatos           #+#    #+#             */
/*   Updated: 2022/11/30 12:58:27 by almatos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			len_read;

	if (fd < 0)
		return (NULL);
	len_read = read(fd, buffer, BUFFER_SIZE);
	line = next_line(buffer, line, len_read);
	return (line);
}

char	*next_line(char *buffer, char *line, int len_read)
{
	if (len_read == 0)
		return (line = NULL);
	line = malloc(MAX * sizeof(char));
	line = gnl_join(line, buffer);
	return (line);
}

char	*gnl_join(char *line, char *buffer)
{
	int	index;

	index = 0;
	while (buffer && buffer[index])
		line[index++] = buffer[index];
	line[index] = '\0';
	while (index != 0)
		buffer[--index] = '\0';
	return (line);
}
