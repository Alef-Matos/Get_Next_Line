# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE   3
# endif

int	gnl_utils_len(const char *str, int flag)
{
    int len;

    len = 0;
    if (flag == 0)
    {
        while (str[len])
            len++;
        return (len);
    }
    if (flag == 1)
    {
        while (str[len] && str[len] != '\n')
            len++;
        return (len);
    }
}

typedef struct s_gnl
{
    char	*line;
    long    read_buffer_size;
    long    size_line;
    long    index;
}	type_gnl;

char	*get_next_line(int fd)
{
    static char	buffer[BUFFER_SIZE + 1];
    type_gnl    gnl;

    gnl.read_buffer_size = gnl_utils_len(buffer, 0);
    gnl.size_line = 0;
    gnl.line = (void *)0;
    gnl.index = 1;
    while (fd >= 0 && gnl.index > 0)
    {
        if (buffer[0] == 0 || gnl.read_buffer_size == 0 )
            gnl.read_buffer_size = read(fd, buffer, BUFFER_SIZE);
        gnl.index = gnl.read_buffer_size;
        if (gnl.read_buffer_size > 0)
        {
            gnl.read_buffer_size = gnl_utils_len(buffer, 1);
            gnl.index = (gnl.index == gnl.read_buffer_size);
            gnl.read_buffer_size += buffer[gnl.read_buffer_size] == '\n';
        }
    }
    return (gnl.line);
}

int	main(void)
{
    char	*line = NULL;
    int		fd = open("/home/almatos/get_next_line/Desenvolv/gnl_test", O_RDONLY);
    line = get_next_line(fd);
    printf("%s", line);
    free(line);
    close(fd);
    return 0;
}