#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4
#endif

int	len(char *str)
{
    int	len;

    len = 0;
    while (str && str[len] && str[len] != '\n')
        len++;
    if (str && str[len] == '\n')
        len++;
    return (len);
}

int	clean(char *buffer)
{
    int	index_a;
    int	index_b;
    int	flag;

    index_a = 0;
    index_b = 0;
    flag = 0;
    while (buffer[index_a])
    {
        if (flag > 0)
            buffer[index_b++] = buffer[index_a];
        if (buffer[index_a] == '\n')
            flag = 1;
        buffer[index_a] = '\0';
        index_a++;
    }
    return (flag);
}

char	*next_line(char *buffer, char *line)
{
    char	*tmp_line;
    int		index_a;
    int		index_b;

    tmp_line = malloc((len(buffer) + len(line) + 1) * sizeof(char));
    if (!tmp_line)
        return (0);
    index_a = 0;
    while (line && line[index_a])
    {
        tmp_line[index_a] = line[index_a];
        index_a++;
    }
    index_b = 0;
    while (buffer[index_b] && buffer[index_b] != '\n')
        tmp_line[index_a++] = buffer[index_b++];
    if (buffer[index_b] == '\n')
        tmp_line[index_a++] = '\n';
    tmp_line[index_a] = '\0';
    if (line)
        free(line);
    return (tmp_line);
}

char	*get_next_line(long fd)
{
    static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
    char		*line;
    long		size_read;

    if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE <= 0)
        return (NULL);
    line = next_line(buffer[fd], 0);
    if (clean(buffer[fd]))
        return (line);
    size_read = 1;
    while (size_read > 0)
    {
        size_read = read(fd, buffer[fd], BUFFER_SIZE);
        if (size_read == -1 || (size_read == 0 && line[0] == '\0'))
        {
            free(line);
            return (NULL);
        }
        line = next_line(buffer[fd], line);
        if (clean(buffer[fd]))
            break ;
    }
    return (line);
}

int	main(void)
{
    int     index;
    char	*line = NULL;
    int     fd[3];

    index = 0;
    fd[0] = open("/nfs/homes/almatos/CLionProjects/gnl/texto", O_RDONLY);
    fd[1] = open("/nfs/homes/almatos/CLionProjects/gnl/texto2", O_RDONLY);
    fd[2] = open("/nfs/homes/almatos/CLionProjects/gnl/texto3", O_RDONLY);
    printf("####################### BONUS GET_NEXT_LINE ######################\n\n");
    printf("************************ PRIMEIRA CHAMADA ************************\n");
    while (index <= 2)
    {
        line = get_next_line(fd[index]);
        printf("Arquivo %d: %s ", index + 1, line);
        free(line);
        index++;
    }
    index = 0;
    printf("************************* NEXT LINE ****************************\n");
    while (index <= 2)
    {
        line = get_next_line(fd[index]);
        printf("Arquivo %d: %s ", index + 1, line);
        free(line);
        index++;
    }
    printf("\n#################################################################\n");
    close(fd[0]);
    close(fd[1]);
    close(fd[2]);
    return 0;
}