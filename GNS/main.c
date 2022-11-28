# include	<stdlib.h>
# include	<unistd.h>
# include   <stdio.h>
# include	<fcntl.h>

int	main(void)
{
    char	*line = NULL;
    int		fd = open("/nfs/homes/almatos/get_next_line/GNS", O_RDONLY);
    line = get_next_line(fd);
    printf("%s", line);
    free(line);
    close(fd);
    return 0;
}