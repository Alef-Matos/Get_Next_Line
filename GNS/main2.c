# include	<stdlib.h>
# include	<unistd.h>
# include   <stdio.h>
# include	<fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
#  define MAX 20001
# endif

typedef struct s_gnl
{
	char			*line;
	int				len_read;
	int				len_buff;
	int				index;
}t_gnl;

char	*next_line(char *buffer, char *line, int len_read);
char	*gnl_join(char *line, char *buff, int l_read, int l_line);

int		gnl_len(char *str)
{
	int	len;

	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	return (len);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	t_gnl		s;

	if (fd < 0)
		return (NULL);
	s.len_read = read(fd, buff, BUFFER_SIZE);
	s.line = next_line(buff, s.line, s.len_read);
	return (s.line);
}

char	*next_line(char *buffer, char *line, int len_read)
{
	int	len_line;

	len_line = gnl_len(line);
	line = gnl_join(line, buffer, len_read, len_line);
	return (line);
}

char	*gnl_join(char *line, char *buff, int l_read, int l_line)
{
	int	i;
	int	j;

	i = -1;
	while (buff && buff[++i])
	{
		line[i + l_line] = buff[i];
		if (buff[i] == '\n')
			break;
	}
	if (line[i + l_line] == '\n')
		line[(i + l_line) + 1] = '\0';
	else
		line[(i + l_line)] = '\0';
	j = 0;
	while (i != l_read)
		buff[j++] = buff[i++ + 1];
	while (j != l_read)
		buff[j++] = '\0';
	return (line);
}

int	main(void)
{
    char	*line = NULL;
    int		fd = open("/nfs/homes/almatos/get_next_line/GNS/texto", O_RDONLY);
    line = get_next_line(fd);
    printf("%s", line);
	printf("\n");
    close(fd);
    return 0;
}