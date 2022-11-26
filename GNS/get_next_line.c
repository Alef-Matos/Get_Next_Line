/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almatos <almatos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:27:07 by almatos           #+#    #+#             */
/*   Updated: 2022/11/26 15:02:10 by almatos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	t_gnl		gnl;

	gnl.read_buffer_size = gnl_utils_len(buffer, 0);
	gnl.size_line = 0;
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
/* Linha 29: Enquanto o tamanho do buffer lido for maior que 0 será 
			 executada as linhas 31, 32, 33 e 34.
*/
/* Linha 31: Conta o tamanho do buffer lido até encontrar caracter '\0'
			 ou uma quebra de linha '\n'.
*/
/* Linha 32: O index recebe a condição (se index for igual ao tamanho
			 do buffer lido) se verdadeira resultado = 1 falso = 0;
*/
/* Linha 33: tamanho do buffer lido é igual a ele mesmo somado com a
			 condição (se buffer na posição atual for igual a uma 
			 quebra de linha) se for verdadeira é + 1 se for falça é + 0;
 */