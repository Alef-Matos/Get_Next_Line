/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almatos <almatos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:27:04 by almatos           #+#    #+#             */
/*   Updated: 2022/12/24 19:48:09 by almatos          ###   ########.fr       */
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

int	clear_buffer(char *buffer)
{
	t_struct	data;

	data.alpha_index = 0;
	data.beta_index = 0;
	data.new_line_faund = 0;
	while (buffer[data.alpha_index] != '\0')
	{
		if (data.new_line_faund > 0)
			buffer[data.beta_index++] = buffer[data.alpha_index];
		data.new_line_faund += (buffer[data.alpha_index] == '\n');
		buffer[data.alpha_index++] = '\0';
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
	data.alpha_index = -1;
	while (new_line && new_line[++data.alpha_index] != '\0')
		data.new_line[data.alpha_index] = new_line[data.alpha_index];
	data.beta_index = 0;
	data.alpha_index += (data.alpha_index == -1);
	while (buffer[data.beta_index] != '\0' && buffer[data.beta_index] != '\n')
		data.new_line[data.alpha_index++] = buffer[data.beta_index++];
	if (buffer[data.beta_index] == '\n')
		data.new_line[data.alpha_index++] = '\n';
	data.new_line[data.alpha_index] = '\0';
	if (new_line)
		free(new_line);
	return (data.new_line);
}
