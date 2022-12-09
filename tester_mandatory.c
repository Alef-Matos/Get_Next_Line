/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_mandatory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almatos <almatos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:20:14 by almatos           #+#    #+#             */
/*   Updated: 2022/12/09 15:22:32 by almatos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Teste para o 'MANDATORY', abre um arquivo e imprime as linhas.
// Para funcionar você tem que criar 1 arquivo e colocar neles
// pelo menos duas linhas.
// Não esqueça de mudar o caminho para os seus arquivos
// exemplo: fd = open("Caminho do arquivo AQUI", O_RDONLY).
// Executa o GET_NEXT_LINE em sequência de acordo com a variável
// 'line' altere ela para escolher quantas chamadas do 
// 'GET_NEXT_LINE' você quer.

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"

int	main(void)
{
	int		index;
	char	*line;
	int		fd;
	int		linhas;

	linhas = 30;
	index = -1;
	fd = open("Caminho do arquivo AQUI", O_RDONLY);
	printf("################### GET_NEXT_LINE ####################\n");
	while (++index <= linhas)
	{
		line = get_next_line(fd);
		printf(" - Next Line %d: %s", index + 1, line);
		free(line);
	}
	printf("\n###########################################################\n");
	close(fd);
	return (0);
}
