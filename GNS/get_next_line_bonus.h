/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almatos <almatos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:27:10 by almatos           #+#    #+#             */
/*   Updated: 2022/12/24 19:32:22 by almatos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H

# define GET_NEXT_LINE_BONUS_H

# include	<stdlib.h>
# include	<unistd.h>
# include   <stdio.h>
# include	<fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 45
# endif

typedef struct s_gnl
{
	char	*new_line;
	int		index_a;
	int		index_b;
	int		new_line_faund;
	int		size_buffer;
	int		size_line;
}	t_struct;

int		clear_buffer(char *buffer);
char	*create_line(char *buffer, char *new_line);
char	*get_next_line(long fd);

#endif