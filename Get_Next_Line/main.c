#include "get_next_line.h"
#include <stdio.h>

void foo()
{
	system("leaks a.out");
}

int main(void)
{
	atexit(foo);
	int fd = open("test.txt", O_RDONLY);
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
}