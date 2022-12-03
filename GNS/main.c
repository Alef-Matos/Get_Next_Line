#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
# define MAX 20001
#endif

typedef struct b_gnl
{
	char	*line;
	int		len_read;
	int		flag;
	int		index;
}			t_gnl;

char		*next_line(char *buffer, char *line, int len_read);
char		*gnl_join(char *line, char *buff, int l_read, int l_line);
int			gnl_len(const char *str, int flag);

int	gnl_len(const char *str, int flag)
{
	int	len;

	len = 0;
	if (flag == 0)
	{
		while (str[len] && str[len] != '\n')
			len++;
	}
	if (flag == 1)
	{
		while (str[len])
		{
			if (str[len] == '\n')
				return (1);
			else
				return (0);
			len++;
		}
	}
	return (len);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	t_gnl		gnl;

	gnl.index = -1;
	gnl.flag = 0;
	if (fd < 0)
		return (NULL);
	gnl.line = malloc(MAX * sizeof(char));
	while (gnl.flag == 0 && gnl.len_read != 0)
	{
		if (gnl.flag == 0 && buffer[0] == 0)
			gnl.len_read = read(fd, buffer, BUFFER_SIZE);
		while (buffer[++gnl.index] != '\n' && buffer[gnl.index])
			gnl.flag += (buffer[gnl.index + 1] == '\n');
		gnl.line = next_line(buffer, gnl.line, gnl.len_read);
		gnl.index = -1;
	}
	if (gnl.len_read == 0 && gnl_len(gnl.line, 0) == 0)
		return (NULL);
	return (gnl.line);
}

char	*next_line(char *buffer, char *line, int len_read)
{
	int	l_line;
	int	i;
	int	flag;

	i = -1;
	flag = 0;
	if (len_read == 0)
		return (line);
	while (line[++i])
		flag = flag + (line[i] == '\n');
	if (flag == 0)
	{
		l_line = gnl_len(line, 0);
		line = gnl_join(line, buffer, len_read, l_line);
	}
	return (line);
}

char	*gnl_join(char *line, char *buff, int l_read, int l_line)
{
	int	index;
	int	j;

	index = -1;
	while (buff && buff[++index])
	{
		line[index + l_line] = buff[index];
		if (buff[index] == '\n')
			break ;
	}
	if (line[index + l_line] == '\n')
		line[(index + l_line) + 1] = '\0';
	else
		line[(index + l_line)] = '\0';
	j = 0;
	while (index != l_read)
		buff[j++] = buff[index++ + 1];
	while (j != l_read)
		buff[j++] = '\0';
	return (line);
}

int	main(void)
{
	char *line = NULL;
	int fd = open("/nfs/homes/almatos/get_next_line/GNS/texto", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	printf("\n");
	close(fd);
	return (0);
}