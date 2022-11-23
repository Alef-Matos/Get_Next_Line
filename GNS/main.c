/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almatos <almatos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:55:51 by almatos           #+#    #+#             */
/*   Updated: 2022/11/23 13:02:22 by almatos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	*gnl;
	int		fd;

	fd = open("texto", O_RDWR);
	gnl = get_next_line(fd);
	close(fd);
	printf("teste: %s", gnl);
	return (0);
}
