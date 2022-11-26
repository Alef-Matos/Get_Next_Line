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