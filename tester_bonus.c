/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almatos <almatos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:57:12 by almatos           #+#    #+#             */
/*   Updated: 2022/12/08 23:00:36 by almatos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "get_next_line_bonus.h"

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
	int		fd[14];
	int		repetition;

	repetition = 10;
	line = NULL;
	index = 0;
	fd[0] = open("Caminho do arquivo AQUI", O_RDONLY);
	fd[1] = open("Caminho do arquivo AQUI", O_RDONLY);
	fd[2] = open("Caminho do arquivo AQUI", O_RDONLY);
	fd[3] = open("Caminho do arquivo AQUI", O_RDONLY);
	fd[4] = open("Caminho do arquivo AQUI", O_RDONLY);
	fd[5] = open("Caminho do arquivo AQUI", O_RDONLY);
	fd[6] = open("Caminho do arquivo AQUI", O_RDONLY);
	fd[7] = open("Caminho do arquivo AQUI", O_RDONLY);
	fd[8] = open("Caminho do arquivo AQUI", O_RDONLY);
	fd[9] = open("Caminho do arquivo AQUI", O_RDONLY);
	fd[10] = open("Caminho do arquivo AQUI", O_RDONLY);
	fd[11] = open("Caminho do arquivo AQUI", O_RDONLY);
	fd[12] = open("Caminho do arquivo AQUI", O_RDONLY);
	fd[13] = open("Caminho do arquivo AQUI", O_RDONLY);
	printf("#################### BONUS GET_NEXT_LINE #####################\n\n");
	printf("********************** PRIMEIRA CHAMADA ************************\n");
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
			printf("\n***************** NEXT LINE %d ******************\n", cont);
		cont++;
		index = -1;
		repetition--;
	}
	printf("\n###########################################################\n");
	while (++index <= 13)
		close(fd[index]);
	return (0);
}
