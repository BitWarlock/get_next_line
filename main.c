#include "src/get_next_line.h"
#include <stdio.h>
#include <sys/fcntl.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
	int	i;
	int	fd;
	unsigned int	file;
	char		*line;
	/* Add your test files here */
	char		*files[] = {"tests/empty.txt"};
	/*, "tests/multiple_new_lines.txt", "tests/one_character.txt",\
		"tests/empty.txt", "tests/long_line.txt", "tests/harry_potter.txt"};*/
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
		printf("\033[0;32m");
		printf("\n\n\t\tTest %d for file %s\n\n\n", file + 1, files[file]);
		printf("\033[0m");
		while ((line = get_next_line(fd)) != NULL)
		{
        		printf("Line number %02d: -> %s\n", i, line);
			free(line);
        		i++;
		}
		close(fd);
		file++;
	}
	return 0;
}
