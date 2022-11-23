/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almatos <almatos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:26:59 by almatos           #+#    #+#             */
/*   Updated: 2022/11/23 10:00:14 by almatos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gns_utils_len(const char *str, int len)
{
	while (*str++)
		len++;
	return (len);
}

char	*gns_utils_strjoin(char const *str_1, char const *str_2)
{
	char	*str_join;
	size_t	len;

	if (!str_1 || !str_2)
		return (NULL);
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