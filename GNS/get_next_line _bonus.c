/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line _bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almatos <almatos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:27:07 by almatos           #+#    #+#             */
/*   Updated: 2022/12/08 11:29:05 by almatos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(long fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	long		size_read;

	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	line = next_line(buffer[fd], 0);
	if (clean(buffer[fd]))
		return (line);
	size_read = 1;
	while (size_read > 0)
	{
		size_read = read(fd, buffer[fd], BUFFER_SIZE);
		if (size_read == -1 || (size_read == 0 && line[0] == '\0'))
		{
			free(line);
			return (NULL);
		}
		line = next_line(buffer[fd], line);
		if (clean(buffer[fd]))
			break ;
	}
	return (line);
}
