#include "get_next_line.h"
#include <stdio.h>
#include <sys/fcntl.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
	int	i;
	int	fd;
	int	file;
	char		*line;
	char		*files[] = {"long_line.txt", "mul_nl.txt", "one_ch.txt", "empty.txt", "basic.txt", "basic.txt"};

	file = 0;
	while (file < sizeof(files) / sizeof(files[0]))
	{
		i = 1;
		fd = open(files[file], O_RDWR);
		if (!fd)
		{
			perror("Error opening file");
			return (1);
		}
		printf("\n\n\tTest %d for file %s\n\n", file, files[file]);
		while ((line = get_next_line(fd)) != NULL)
		{
        		printf("line: %02d -> %s\n", i, line);
			free(line);
        		i++;
		}
		close(fd);
		file++;
	}
	return 0;
}
