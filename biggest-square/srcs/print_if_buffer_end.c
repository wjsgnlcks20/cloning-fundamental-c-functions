#include <unistd.h>
#include "../includes/buffer.h"

void	write_pass_nul(char *buffer, int bytes)
{
	int	start;

	start = 0;
	while (buffer[start] == '\0')
		start++;
	write(1, buffer + start, bytes - start);
}

void	read_next_if_buffer_end(int fd, int *idx, char *buffer, int *bytes)
{
	if (*idx + 1 != *bytes)
		return ;
	*idx = -1;
	*bytes = read(fd, buffer, BUFFER_SIZE);
}

void	print_if_buffer_end(int fd, int *idx, char *buffer, int *bytes)
{
	if (*idx + 1 != *bytes)
		return ;
	write_pass_nul(buffer, *bytes);
	*idx = -1;
	*bytes = read(fd, buffer, BUFFER_SIZE);
}
