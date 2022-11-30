# include	<stdlib.h>
# include	<unistd.h>
# include   <stdio.h>
# include	<fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
#  define MAX 20001
# endif

char	*next_line(char *buffer, char *line, int len_read, int index);
char	*gnl_join(char *line, char *buffer, int teste);

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE +1];
	char			*line;
	int				len_read;
	int				flag;
	int				index;

	index = -1;
	if (fd < 0)
		return (NULL);
	flag = 0;
	while (flag == 0 && len_read != 0)
	{
		len_read = read(fd, buffer, BUFFER_SIZE);
		while (buffer[++index] != '\n' && buffer[index])
			flag = flag + (buffer[index + 1] == '\n');
		line = next_line(buffer, line, len_read, index);
		index = -1;
	}
	return (line);
}

char	*next_line(char *buffer, char *line, int len_read, int index)
{
	int	teste;

	teste = len_read - index;
	if (len_read == 0)
		return (line);
	line = malloc(MAX * sizeof(char));
	line = gnl_join(line, buffer, teste);
	return (line);
}

char	*gnl_join(char *line, char *buffer, int teste)
{
	int	index;

	index = 0;
	while (buffer && buffer[index])
		line[index++] = buffer[index];
	line[index] = '\0';
	while (index != 0)
		buffer[--index] = '\0';
	return (line);
}

int	main(void)
{
    char	*line = NULL;
    int		fd = open("/nfs/homes/almatos/get_next_line/GNS/texto", O_RDONLY);
    line = get_next_line(fd);
    printf("%s", line);
    free(line);
    close(fd);
    return 0;
}