/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almatos <almatos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:27:04 by almatos           #+#    #+#             */
/*   Updated: 2022/12/09 11:04:10 by almatos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		c.flag += (buffer[c.index_a] == '\n');
		buffer[c.index_a++] = '\0';
	}
	return (c.flag);
}

char	*next_line(char *buffer, char *line)
{
	t_struct	n;

	n.c_line = 0;
	n.c_buff = 0;
	while (buffer[n.c_buff] && buffer[n.c_buff] != '\n')
		n.c_buff++;
	n.c_buff += (buffer[n.c_buff] == '\n');
	while (line && line[n.c_line] && line[n.c_line] != '\n')
		n.c_line++;
	n.temp_line = malloc((n.c_line + n.c_buff + 1) * sizeof(char));
	if (!n.temp_line)
		return (0);
	n.index_a = -1;
	while (line && line[++n.index_a])
		n.temp_line[n.index_a] = line[n.index_a];
	n.index_b = 0;
	n.index_a += (n.index_a == -1);
	while (buffer[n.index_b] && buffer[n.index_b] != '\n')
		n.temp_line[n.index_a++] = buffer[n.index_b++];
	if (buffer[n.index_b] == '\n')
		n.temp_line[n.index_a++] = '\n';
	n.temp_line[n.index_a] = '\0';
	if (line)
		free(line);
	return (n.temp_line);
}
