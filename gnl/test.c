# include <stdio.h>
#include "get_next_line.h"

int		main(int argc, char *argv[])
{
	int fd1;
	int fd2;
	char *line = NULL;
	int i;
	int j;

	if (argc == 1)
	{
		i = get_next_line(2, &line);
		printf("~~~fd: %d line: %s return: %d~~~\n", 0, line, i);
		free(line);
	}
	if (argc == 2)
	{
		fd1 = open(argv[1], O_RDONLY);
		printf("BUFFER_SIZE: %d\n", BUFFER_SIZE);
		do
		{
			i = get_next_line(fd1, &line);
			printf("~~~fd: %d line: %s return: %d~~~\n", fd1, line, i);
			free(line);
		} while (i > 0);
		// free(line);
	}
	if (argc == 3)
	{
		fd1 = open(argv[1], O_RDONLY);
		fd2 = open(argv[2], O_RDONLY);
		printf("BUFFER_SIZE: %d\n", BUFFER_SIZE);
		do 
		{
			i = get_next_line(fd1, &line);
			printf("~~~fd: %d line: %s return: %d~~~\n", fd1, line, i);
			free(line);
			j = get_next_line(fd2, &line);
			printf("~~~fd: %d line: %s return: %d~~~\n", fd2, line, j);
		} while (i > 0 || j > 0);
		free(line);
	}
	return (0);
}
