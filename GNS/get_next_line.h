/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almatos <almatos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:27:10 by almatos           #+#    #+#             */
/*   Updated: 2022/11/30 12:58:14 by almatos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include	<stdlib.h>
# include	<unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 45
#  define MAX 20001
# endif

char	*next_line(char *buffer, char *line, int len_read);
char	*gnl_join(char *line, char *buffer);

#endif