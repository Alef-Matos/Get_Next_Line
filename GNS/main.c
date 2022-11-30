# include	<stdlib.h>
# include	<unistd.h>
# include   <stdio.h>
# include	<fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
#  define MAX 20001
# endif

char	*next_line(char *buffer, char *line, int len_read);
char	*gnl_join(char *line, char *buffer);

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE +1];
	char			*line;
	int				len_read;
	int				cond;
	int				index;

	index = -1;
	if (fd < 0)
		return (NULL);
	if (!buffer[0])
		len_read = read(fd, buffer, BUFFER_SIZE);
	cond = 0;
	while (buffer[++index] != '\n' && buffer[index])
		cond = cond + (buffer[index + 1] == '\n');
	line = next_line(buffer, line, len_read);
	return (line);
}

char	*next_line(char *buffer, char *line, int len_read)
{
	if (len_read == 0)
		return (line = NULL);
	line = malloc(len_read * sizeof(char));
	line = gnl_join(line, buffer);
	return (line);
}

char	*gnl_join(char *line, char *buffer)
{
	int	index;

	index = 0;
	while (buffer && buffer[index])
		line[index++] = buffer[index];
	line[index] = '\0';
	index = 0;
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