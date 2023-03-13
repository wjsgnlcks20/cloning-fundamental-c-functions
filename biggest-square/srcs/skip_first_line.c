#include "../includes/bsq.h"

int	skip_first_line(char *buffer)
{
	int	idx;

	idx = 0;
	while (buffer[idx] != '\n')
		idx++;
	return (idx);
}

int	read_first_line(int fd, char *buffer, int *idx, t_pos *dp_idx)
{
	int	bytes;

	bytes = read(fd, buffer, BUFFER_SIZE);
	*idx = skip_first_line(buffer);
	dp_init_pos(dp_idx);
	return (bytes);
}
