/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almatos <almatos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:27:04 by almatos           #+#    #+#             */
/*   Updated: 2022/12/07 15:59:58 by almatos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	int	index_a;
	int	index_b;
	int	flag;

	index_a = 0;
	index_b = 0;
	flag = 0;
	while (buffer[index_a])
	{
		if (flag > 0)
			buffer[index_b++] = buffer[index_a];
		if (buffer[index_a] == '\n')
			flag = 1;
		buffer[index_a] = '\0';
		index_a++;
	}
	return (flag);
}

char	*next_line(char *buffer, char *line)
{
	char	*tmp_line;
	int		index_a;
	int		index_b;

	tmp_line = malloc((len(buffer) + len(line) + 1) * sizeof(char));
	if (!tmp_line)
		return (0);
	index_a = 0;
	while (line && line[index_a])
	{
		tmp_line[index_a] = line[index_a];
		index_a++;
	}
	index_b = 0;
	while (buffer[index_b] && buffer[index_b] != '\n')
		tmp_line[index_a++] = buffer[index_b++];
	if (buffer[index_b] == '\n')
		tmp_line[index_a++] = '\n';
	tmp_line[index_a] = '\0';
	if (line)
		free(line);
	return (tmp_line);
}
