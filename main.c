#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int	fd[3];
	int	read;
	char *line;
	int	n;
	int	closed;

	read = 1;
	fd[0] = open("test1.txt", O_RDONLY);
	fd[1] = open("test2.txt", O_RDONLY);
	fd[2] = open("test3.txt", O_RDONLY);
	n = 0;
	closed = 0;
	while (read)
	{
		if (0 && n == 3)
			n = 0;
		line = get_next_line(fd[0]);	
		//printf("LINE: %s FD: %d", line, fd[0]);
		printf("LINE: %s", line);
		read = ft_len(line);
		if (0 && read == 0)
		{
			closed++;
			close(fd[n]);
		}
		free (line);
		n++;
	}
	close(fd[0]);
//	printf("ADD line: %p", line);	
//	system("leaks a.out");
	return (0);
}
