#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
	int fd = open("harry.txt", O_RDWR);
	get_next_line(fd);

	return EXIT_SUCCESS;
}
