#include "../includes/bsq.h"

void	erase_first_line(char *buffer, int first_newline_idx)
{
	int	i;

	i = 0;
	while (i <= first_newline_idx)
		buffer[i++] = '\0';
}

void	print_max_square(char *file_name, t_pos max_pos, char square)
{
	int		fd;
	int		idx;
	int		bytes;
	char	buffer[BUFFER_SIZE];
	t_pos	cur;

	fd = open(file_name, O_RDONLY);
	bytes = read(fd, buffer, BUFFER_SIZE);
	idx = skip_first_line(buffer);
	erase_first_line(buffer, idx);
	dp_init_pos(&cur);
	while (++idx < bytes)
	{
		if (!is_newline(-1, buffer[idx], &cur) && is_in_square(cur, max_pos))
			buffer[idx] = square;
		cur.x++;
		print_if_buffer_end(fd, &idx, buffer, &bytes);
	}
	write(1, "\n", 1);
	close(fd);
}
