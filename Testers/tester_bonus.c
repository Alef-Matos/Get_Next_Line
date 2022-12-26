/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almatos <almatos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:57:12 by almatos           #+#    #+#             */
/*   Updated: 2022/12/09 16:11:54 by almatos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
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
	n.temp_line = malloc((n.c_line + n.c_buff + 1) * sizeof(char));
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

	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE <= 0)
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

// Teste para o 'BONUS', abre o maximo de arquivos em simultâneo.
// Para funcionar você tem que criar 13 arquivos e colocar neles
// pelo menos duas linhas.
// Não esqueça de mudar o caminho para os seus arquivos
// exemplo: fd[0] = open("Caminho do arquivo AQUI", O_RDONLY).
// Executa o GET_NEXT_LINE em sequência de acordo com a variável
// 'repetition' altere ela para escolher quantas chamadas do 
// 'GET_NEXT_LINE' você quer.
int	main(void)
{
	int		index;
	int		cont;
	char	*line;
	int		fd[16];
	int		repetition;

	repetition = 40;
	line = NULL;
	index = 0;
	fd[0] = open("/nfs/homes/almatos/CLionProjects/gnl/texto", O_RDONLY);
	fd[1] = open("/nfs/homes/almatos/CLionProjects/gnl/texto2", O_RDONLY);
	fd[2] = open("/nfs/homes/almatos/CLionProjects/gnl/texto3", O_RDONLY);
	fd[3] = open("/nfs/homes/almatos/CLionProjects/gnl/texto4", O_RDONLY);
	fd[4] = open("/nfs/homes/almatos/CLionProjects/gnl/texto5", O_RDONLY);
	fd[5] = open("/nfs/homes/almatos/CLionProjects/gnl/texto6", O_RDONLY);
	fd[6] = open("/nfs/homes/almatos/CLionProjects/gnl/texto7", O_RDONLY);
	fd[7] = open("/nfs/homes/almatos/CLionProjects/gnl/texto8", O_RDONLY);
	fd[8] = open("/nfs/homes/almatos/CLionProjects/gnl/texto9", O_RDONLY);
	fd[9] = open("/nfs/homes/almatos/CLionProjects/gnl/texto10", O_RDONLY);
	fd[10] = open("/nfs/homes/almatos/CLionProjects/gnl/texto11", O_RDONLY);
	fd[11] = open("/nfs/homes/almatos/CLionProjects/gnl/texto12", O_RDONLY);
	fd[12] = open("/nfs/homes/almatos/CLionProjects/gnl/texto13", O_RDONLY);
	fd[13] = open("/nfs/homes/almatos/CLionProjects/gnl/texto14", O_RDONLY);
	fd[14] = open("/nfs/homes/almatos/CLionProjects/gnl/texto15", O_RDONLY);
	printf("#################### BONUS GET_NEXT_LINE #####################\n\n");
	printf("********************** PRIMEIRA CHAMADA ************************\n");
	cont = 2;
	index = -1;
	while (repetition > 0)
	{
		while (++index <= 14)
		{
			line = get_next_line(fd[index]);
			printf(" - Arquivo %d: %s", index + 1, line);
			free(line);
		}
		if (repetition - 1 != 0)
			printf("\n***************** NEXT LINE %d ******************\n", cont);
		cont++;
		index = -1;
		repetition--;
	}
	printf("\n###########################################################\n");
	while (++index <= 14)
		close(fd[index]);
	return (0);
}
