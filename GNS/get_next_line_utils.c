/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almatos <almatos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:27:04 by almatos           #+#    #+#             */
/*   Updated: 2022/11/28 16:37:19 by almatos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_len(const char *str)
{
	int	len;

	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	return (len);
}