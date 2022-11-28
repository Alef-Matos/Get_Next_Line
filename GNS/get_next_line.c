/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almatos <almatos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:27:07 by almatos           #+#    #+#             */
/*   Updated: 2022/11/28 18:42:42 by almatos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*nextline(char *line, char *buff, int size_buff, int *size_line)
{
	t_gnl	next;

	next.line = line
	next.size_line = 0;
	next.size_buff = -1;
	next.index = 0;
	*size_line = *size_line + size_buff;
	if (line)
	{
		line[*size_line] = 0;
		while ()
	}
}

char	*get_next_line(int fd)
{
	static char	*buff[BUFFER_SIZE + 1];
	t_gnl		gnl;

	gnl.size_line = 0;
	gnl.index = 1;
	gnl.size_buff = gnl_len(buff);
	gnl.line = NULL;
	if (fd < 0)
		return (NULL);
	while (gnl.index > 0)
	{
		if (!buff[0] || !gnl.size_buff)
			gnl.size_buff = read(fd, buff, BUFFER_SIZE);
		gnl.index = gnl.size_buff;
		if (gnl.size_buff > 0)
		{
			gnl.size_buff = 0;
			gnl.size_buff = gnl_len(buff);
			gnl.index = (gnl.size_buff == gnl.index);
			gnl.size_buff = gnl.size_buff + (buff[gnl.size_buff] == '\n');
			gnl.line = next_line(gnl.line, buff, gnl.size_buff, &gnl.size_line);
		}
	}
	return (gnl.line);
}

void	gnl_buffer(char *buff, long *size_line, long *size_buff, char *line)
{
	long	s_line;
	long	s_buff;
	long	index;

	index = 0;
	s_buff = *size_buff;
	s_line = *size_line;
	while (buff && buff[s_line])
	{
		if (s_line < s_buff)
		{
			line[index] = buff[s_line];
			index++;
		}
		else
		{
			buff[s_buff] = buff[s_line];
			s_buff++;
		}
		buff[s_line] = 0;
		s_line++;
	}
	*size_buff = s_buff;
	*size_line = s_line;
}
