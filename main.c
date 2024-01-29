#include "get_next_line.h"
#include <libc.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/fcntl.h>

int main(void)
{
	int fd = open("basic.txt", O_RDWR | O_CREAT, 0777);
	char *str = "123\n\n456\n789\n\n\nabcdefg\n";
	dprintf(fd, "%s", str);
	lseek(fd, -ft_strlen(str), SEEK_END);
	str = get_next_line(fd);
	int i = 1;
	while (str)
	{
		printf("%d : %s\n", i, str);
		free(str);
		str = get_next_line(fd);
		i++;
	}
	// system("leaks a.out");
	return EXIT_SUCCESS;
}
