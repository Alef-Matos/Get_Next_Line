# include	<stdlib.h>
# include	<unistd.h>
# include	<stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 45
#  define MAX 20001
# endif

char    *gnl_join(char *line, char *buffer)
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

int    main(void)
{
    static char buffer[6] = "teste";
    char        *line;

    line = malloc(MAX * sizeof(char));
    line = gnl_join(line, buffer);
    printf("%s\n", line);
    printf("%s", buffer);
    return (0);
}
