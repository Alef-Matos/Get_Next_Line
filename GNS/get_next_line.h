/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almatos <almatos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:27:10 by almatos           #+#    #+#             */
/*   Updated: 2022/11/23 10:54:00 by almatos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 45
# endif

# include	<stdlib.h>
# include	<unistd.h>

char	*gns_utils_strjoin(char const *str_1, char const *str_2);
int		gns_utils_len(const char *str, int len);














#endif