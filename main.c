/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almatos <almatos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:57:12 by almatos           #+#    #+#             */
/*   Updated: 2022/12/07 17:59:10 by almatos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

//BONUS

int	main(void)
{
	int		index;
	char	*line;
	int		fd[3];

	line = NULL;
	index = 0;
	fd[0] = open("arquivo1", O_RDONLY);
	fd[1] = open("arquivo2", O_RDONLY);
	fd[2] = open("arquivo3", O_RDONLY);
	printf("####################### BONUS GET_NEXT_LINE ######################\n\n");
	printf("************************ PRIMEIRA CHAMADA ************************\n");
	while (index <= 2)
	{
		line = get_next_line(fd[index]);
		printf("Arquivo %d: %s ", index + 1, line);
		free(line);
		index++;
	}
	index = 0;
	printf("************************* NEXT LINE ****************************\n");
	while (index <= 2)
	{
		line = get_next_line(fd[index]);
		printf("Arquivo %d: %s ", index + 1, line);
		free(line);
		index++;
	}
	printf("\n#################################################################\n");
	close(fd[0]);
	close(fd[1]);
	close(fd[2]);
	return (0);
}
