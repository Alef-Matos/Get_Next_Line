/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almatos <almatos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:27:04 by almatos           #+#    #+#             */
/*   Updated: 2022/12/08 12:30:39 by almatos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	len(char *str)
{
	int	len;

	len = 0;
	while (str && str[len] && str[len] != '\n')
		len++;
	if (str && str[len] == '\n')
		len++;
	return (len);
}

int	clean(char *buffer)
{
	t_struct	c;

	c.index_a = 0;
	c.index_b = 0;
	c.flag = 0;
	while (buffer[c.index_a])
	{
		if (c.flag > 0)
			buffer[c.index_b++] = buffer[c.index_a];
		if (buffer[c.index_a] == '\n')
			c.flag = 1;
		buffer[c.index_a++] = '\0';
	}
	return (c.flag);
}

char	*next_line(char *buffer, char *line)
{
	t_struct	l;

	l.tmp_line = malloc((len(buffer) + len(line) + 1) * sizeof(char));
	if (!l.tmp_line)
		return (0);
	l.index_a = -1;
	while (line && line[++l.index_a])
		l.tmp_line[l.index_a] = line[l.index_a];
	l.index_b = 0;
	l.index_a += (l.index_a == -1);
	while (buffer[l.index_b] && buffer[l.index_b] != '\n')
		l.tmp_line[l.index_a++] = buffer[l.index_b++];
	if (buffer[l.index_b] == '\n')
		l.tmp_line[l.index_a++] = '\n';
	l.tmp_line[l.index_a] = '\0';
	if (line)
		free(line);
	return (l.tmp_line);
}
