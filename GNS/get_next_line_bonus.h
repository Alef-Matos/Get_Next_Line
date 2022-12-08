/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almatos <almatos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:27:10 by almatos           #+#    #+#             */
/*   Updated: 2022/12/08 23:10:34 by almatos          ###   ########.fr       */
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
	char	*temp_line;
	int		index_a;
	int		index_b;
	int		flag;
	int		c_buff;
	int		c_line;
}	t_struct;

int		clean(char *buffer);
char	*next_line(char *buffer, char *line);
char	*get_next_line(long fd);

#endif