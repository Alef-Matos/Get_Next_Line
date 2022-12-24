/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almatos <almatos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:27:04 by almatos           #+#    #+#             */
/*   Updated: 2022/12/24 19:27:18 by almatos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almatos <almatos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:27:04 by almatos           #+#    #+#             */
/*   Updated: 2022/12/24 19:08:53 by almatos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	len(char *string)
{
	int	count;

	count = 0;
	if (string == NULL)
		return (0);
	while (string[count] && string[count] != '\n')
		count++;
	count += (string[count] == '\n');
	return (count);
}

int	clean_buffer(char *buffer)
{
	t_struct	data;

	data.index_a = 0;
	data.index_b = 0;
	data.new_line_faund = 0;
	while (buffer[data.index_a])
	{
		if (data.new_line_faund > 0)
			buffer[data.index_b++] = buffer[data.index_a];
		data.new_line_faund += (buffer[data.index_a] == '\n');
		buffer[data.index_a++] = '\0';
	}
	return (data.new_line_faund);
}

char	*create_line(char *buffer, char *new_line)
{
	t_struct	data;

	data.size_line = len(new_line);
	data.size_buffer = len(buffer);
	data.new_line = malloc((data.size_line + data.size_buffer + 1)
			* sizeof(char));
	if (data.new_line == NULL)
		return (0);
	data.index_a = -1;
	while (new_line && new_line[++data.index_a])
		data.new_line[data.index_a] = new_line[data.index_a];
	data.index_b = 0;
	data.index_a += (data.index_a == -1);
	while (buffer[data.index_b] && buffer[data.index_b] != '\n')
		data.new_line[data.index_a++] = buffer[data.index_b++];
	if (buffer[data.index_b] == '\n')
		data.new_line[data.index_a++] = '\n';
	data.new_line[data.index_a] = '\0';
	if (new_line)
		free(new_line);
	return (data.new_line);
}
