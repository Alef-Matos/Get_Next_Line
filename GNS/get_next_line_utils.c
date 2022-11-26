/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almatos <almatos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:27:04 by almatos           #+#    #+#             */
/*   Updated: 2022/11/26 14:36:51 by almatos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_utils_len(const char *str, int flag)
{
	int	len;

	len = 0;
	if (flag == 0)
	{
		while (str[len])
			len++;
		return (len);
	}
	if (flag == 1)
	{
		while (str[len] && str[len] != '\n')
			len++;
		return (len);
	}
}

char	*gns_utils_strjoin(char const *str_1, char const *str_2)
{
	char	*str_join;
	int		len;

	len = gns_utils_len(str_1, 0) + gns_utils_len(str_2, 0);
	str_join = (char *)malloc(len + 1);
	if (!str_join)
		return (NULL);
	while (*str_1)
		*str_join++ = *str_1++;
	while (*str_2)
		*str_join++ = *str_2++;
	*str_join = '\0';
	return (str_join - len);
}
