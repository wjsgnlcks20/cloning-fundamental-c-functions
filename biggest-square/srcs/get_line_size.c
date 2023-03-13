#include <fcntl.h>
#include <unistd.h>
#include "../includes/buffer.h"

int	get_newline_idx(char *str, int size)
{
	int	idx;

	idx = -1;
	while (++idx < size)
	{
		if (str[idx] == '\n')
			return (idx);
	}
	return (-1);
}

int	len_between_newline_within_buffer(char *str, int size)
{
	int	first_idx;
	int	idx;

	idx = -1;
	first_idx = -1;
	while (++idx < size)
	{
		if (str[idx] == '\n' && first_idx < 0)
			first_idx = idx;
		else if (str[idx] == '\n')
			return (idx - first_idx - 1);
	}
	return (-1);
}

long long	len_between_newline_over_buffer(int fd, long long bs, char *buffer)
{
	int	first_idx;
	int	second_idx;
	int	bytes;

	first_idx = get_newline_idx(buffer, BUFFER_SIZE);
	second_idx = -1;
	bytes = 0;
	while (second_idx < 0)
	{
		bs += bytes;
		bytes = read(fd, buffer, BUFFER_SIZE);
		second_idx = get_newline_idx(buffer, BUFFER_SIZE);
	}
	return (bs + second_idx - first_idx - 1);
}

int	get_line_size(char *file_name)
{
	int			fd;
	long long	bytes;
	char		buffer[BUFFER_SIZE];
	int			ret;

	fd = open(file_name, O_RDONLY);
	bytes = read(fd, buffer, BUFFER_SIZE);
	ret = len_between_newline_within_buffer(buffer, BUFFER_SIZE);
	if (ret >= 0)
	{
		close(fd);
		return (ret);
	}
	ret = len_between_newline_over_buffer(fd, bytes, buffer);
	close (fd);
	return (ret);
}
