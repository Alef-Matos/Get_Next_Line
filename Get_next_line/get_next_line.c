/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almatos <almatos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:27:07 by almatos           #+#    #+#             */
/*   Updated: 2022/12/24 19:32:41 by almatos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(long fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*return_line;
	long		size_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	return_line = create_line(buffer, 0);
	if (clear_buffer(buffer))
		return (return_line);
	size_read = 1;
	while (size_read > 0)
	{
		size_read = read(fd, buffer, BUFFER_SIZE);
		if (size_read == -1 || (size_read == 0 && return_line[0] == '\0'))
		{
			free(return_line);
			return (NULL);
		}
		return_line = create_line(buffer, return_line);
		if (clear_buffer(buffer))
			break ;
	}
	return (return_line);
}
