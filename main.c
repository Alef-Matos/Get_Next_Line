/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almatos <almatos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 23:17:52 by almatos           #+#    #+#             */
/*   Updated: 2022/12/08 23:17:54 by almatos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

typedef struct s_gnl
{
	char	*temp_line;
	int		index_a;
	int		index_b;
	int		flag;
	int		c_buff;
	int		c_line;
}			t_struct;

int	clean(char *buffer)
{
	t_struct	c;

	c.index_a = 0;
	c.index_b = 0;
	c.flag = 0;
	while (buffer[c.index_a])
	{
		if (c.flag > 0)
			buffer[c.index_b++] = buffer[c.index_a];
		c.flag += (buffer[c.index_a] == '\n');
		buffer[c.index_a++] = '\0';
	}
	return (c.flag);
}

char	*next_line(char *buffer, char *line)
{
	t_struct	n;

	n.c_line = 0;
	n.c_buff = 0;
	while (buffer[n.c_buff] && buffer[n.c_buff] != '\n')
		n.c_buff++;
	n.c_buff += (buffer[n.c_buff] == '\n');
	while (line && line[n.c_line] && line[n.c_line] != '\n')
		n.c_line++;
	n.temp_line = malloc(n.c_line + n.c_buff + 1);
	if (!n.temp_line)
		return (0);
	n.index_a = -1;
	while (line && line[++n.index_a])
		n.temp_line[n.index_a] = line[n.index_a];
	n.index_b = 0;
	n.index_a += (n.index_a == -1);
	while (buffer[n.index_b] && buffer[n.index_b] != '\n')
		n.temp_line[n.index_a++] = buffer[n.index_b++];
	if (buffer[n.index_b] == '\n')
		n.temp_line[n.index_a++] = '\n';
	n.temp_line[n.index_a] = '\0';
	if (line)
		free(line);
	return (n.temp_line);
}

char	*get_next_line(long fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	long		size_read;

	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	line = next_line(buffer[fd], 0);
	if (clean(buffer[fd]))
		return (line);
	size_read = 1;
	while (size_read > 0)
	{
		size_read = read(fd, buffer[fd], BUFFER_SIZE);
		if (size_read == -1 || (size_read == 0 && line[0] == '\0'))
		{
			free(line);
			return (NULL);
		}
		line = next_line(buffer[fd], line);
		if (clean(buffer[fd]))
			break ;
	}
	return (line);
}

int	main(void)
{
	int		index;
	int		cont;
	char	*line;
	int		fd[14];
	int		repetition;

	repetition = 10;
	line = NULL;
	index = 0;
	fd[0] = open("/mnt/c/alef/testes/texto", O_RDONLY);
	fd[1] = open("/mnt/c/alef/testes/texto2", O_RDONLY);
	fd[2] = open("/mnt/c/alef/testes/texto3", O_RDONLY);
	fd[3] = open("/mnt/c/alef/testes/texto4", O_RDONLY);
	fd[4] = open("/mnt/c/alef/testes/texto5", O_RDONLY);
	fd[5] = open("/mnt/c/alef/testes/texto6", O_RDONLY);
	fd[6] = open("/mnt/c/alef/testes/texto7", O_RDONLY);
	fd[7] = open("/mnt/c/alef/testes/texto8", O_RDONLY);
	fd[8] = open("/mnt/c/alef/testes/texto9", O_RDONLY);
	fd[9] = open("/mnt/c/alef/testes/texto10", O_RDONLY);
	fd[10] = open("/mnt/c/alef/testes/texto11", O_RDONLY);
	fd[11] = open("/mnt/c/alef/testes/texto12", O_RDONLY);
	fd[12] = open("/mnt/c/alef/testes/texto13", O_RDONLY);
	fd[13] = open("/mnt/c/alef/testes/texto14", O_RDONLY);
	printf("################### BONUS GET_NEXT_LINE ####################\n\n");
	printf("******************** PRIMEIRA CHAMADA ********************\n");
	cont = 2;
	index = -1;
	while (repetition > 0)
	{
		while (++index <= 13)
		{
			line = get_next_line(fd[index]);
			printf(" - Arquivo %d: %s", index + 1, line);
			free(line);
		}
		if (repetition - 1 != 0)
			printf("\n***************** NEXT LINE%d *******************\n", cont);
		cont++;
		index = -1;
		repetition--;
	}
	printf("\n###########################################################\n");
	while (++index <= 13)
		close(fd[index]);
	return (0);
}