# include	<stdlib.h>
# include	<unistd.h>
# include	<stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 45
#  define MAX 20001
# endif

char	*next_line(char *buffer, char *line, int len_read)
{
	if (len_read == 0)
		return (line = NULL);
	line = malloc(MAX * sizeof(char));
	line = gnl_join(line, buffer);
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
			break;
	}
	line[(index + l_line) + 1] = '\0';
	j = 0;
	while (index != l_read)
		buff[j++] = buff[index++ + 1];
	while (j != l_read)
		buff[j++] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			len_read;

	if (fd < 0)
		return (NULL);
	len_read = read(fd, buffer, BUFFER_SIZE);
	line = next_line(buffer, line, len_read);
	return (line);
}

int    main(void)
{
    static char buffer[6] = "testetesteteste";
    char        *line;
	int			index;

	index = 0;
    line = calloc(MAX, 1);

    line = gnl_join(line, buffer);
    printf("%s\n", line);
    printf("%s", buffer);
    return (0);
}
