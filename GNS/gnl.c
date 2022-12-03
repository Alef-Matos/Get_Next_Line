#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
# define MAX 20001
#endif

typedef struct s_gnl
{
	char	*line;
	int		len_read;
	int		len_line;
	int		flag;
}			t_gnl;

char		*gnl_join(char *line, char *buff, int l_read, int l_line);
char		*get_line(char *line, char *buff, int l_read);

int	gnl_len(char *str)
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

	s.flag = 0;
	s.line = NULL;
	s.len_read = gnl_len(buff);
	while (fd > 0 && buff[s.len_read - 1] != '\n')
	{
		if (!buff[0] || s.flag == 0)
			s.len_read = read(fd, buff, BUFFER_SIZE);
		s.flag = (buff[s.len_read - 1] == '\n');
		s.line = get_line(s.line, buff, s.len_read);
	}
	return (s.line);
}

char	*get_line(char *line, char *buff, int l_read)
{
	t_gnl	g;

	if (!line)
		g.line = malloc(l_read * sizeof(char));
	if (!g.line)
		return (NULL);
	line = g.line;
	free(g.line);
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
			break ;
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
	char	*line;
	int		fd;

	line = NULL;
	fd = open("/home/almatos/get_next_line/GNS/texto", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	printf("\n");
	close(fd);
	free(line);
	return (0);
}
//	fd = open("/nfs/homes/almatos/get_next_line/GNS/texto", O_RDONLY);