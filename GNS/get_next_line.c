/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almatos <almatos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:27:07 by almatos           #+#    #+#             */
/*   Updated: 2022/11/28 09:47:24 by almatos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	t_gnl		gnl;

	gnl.read_buffer_size = gnl_utils_len(buffer, 0);
	gnl.line = (void *)0;
	gnl.index = 1;
	while (fd >= 0 && gnl.index > 0)
	{
		if (buffer[0] == 0 || gnl.read_buffer_size == 0)
			gnl.read_buffer_size = read(fd, buffer, BUFFER_SIZE);
		gnl.index = gnl.read_buffer_size;
		if (gnl.read_buffer_size > 0)
		{
			gnl.read_buffer_size = gnl_utils_len(buffer, 1);
			gnl.index = (gnl.index == gnl.read_buffer_size);
			gnl.read_buffer_size += (buffer[gnl.read_buffer_size] == '\n');
			// tenho que aplicar uma outra função para tratar das linha
			// no momento ainda estou estudando essa parte.
		}
	}
	return (gnl.line);
}
/*	Linha 17: Declarando uma variavel static do tipo char para armazenar
			  a leitura do 'read', tamanho inicial vai ser o do BUFFER_
			  SIZE mais 1(espaco para o '\0'.

	Linha 18: Declarando uma estutura do tipo s_gnl com nome de gnl para
			  armazenar todas as variaveis usadas no programa.

	Linha 20: Variavel que armazena o tamanho da string (buffer) onde e 
			  armazenada a leitura do 'read'.

	Linha 21: Variavel para armazenar a linha retirada do buffer, sera 
			  o que vai ser retornado no fim do programa, valor inicial
			  NULL.

	Linha 22: Variavel usada 

	Linha 23: Enquanto o fd for valido ou seja maior que -1 e o index 
			  for maior que 0, o arquivo foi bem lido e sera executado
			  todo o codigo a partir da linha 25.

	Linha 25: Enquanto o buffer(variavel que armazena a leitura do read) 
			  na posicao inicial for igual a 0(null) ou a variavel que 
			  armazena o tamanho da leitura do read for igual a 0, 
			  executo a linha 26.

	Linha 26: Variavel 'read_buffer_size' ira receber a funcao read tendo
			  como argumentos o fd, buffer(armazena a leitura do read) e 
			  BUFFER_SIZE (macro que indica o tamanho de bytes da minha 
			  leitura).	 

	Linha 27: O 'index' tera o mesmo valor que que o 'read_buffer_size'.

	Linha 28: Se o tamanho do buffer lido for maior que 0, quer dizer que
			  ocorreu tudo bem e o buffer foi preenchido com os dados do 
			  arquivo. Sera exucutado as linhas 31, 32, 33 e 34.

	Linha 30: Conta o tamanho do buffer lido até encontrar caracter '\0'
			  ou uma quebra de linha '\n'.

	Linha 31: O index recebe a condição (se index for igual ao tamanho
			  do buffer lido) se verdadeira resultado = 1 falso = 0;

	Linha 32: tamanho do buffer lido é igual a ele mesmo somado com a
			  condição (se buffer na posição atual for igual a uma 
			  quebra de linha) se for verdadeira é + 1 se for falça é + 0;
*/