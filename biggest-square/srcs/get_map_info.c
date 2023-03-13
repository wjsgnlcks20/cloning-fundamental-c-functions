#include "../includes/bsq.h"

int	is_any_mark_same(char *first_line, int len)
{
	if (first_line[len - 1] == first_line[len - 2])
		return (1);
	if (first_line[len - 1] == first_line[len - 3])
		return (1);
	if (first_line[len - 2] == first_line[len - 3])
		return (1);
	return (0);
}

int	validate_first_line(char *first_line, int len)
{
	int	i;

	i = -1;
	if (len < 4 || is_any_mark_same(first_line, len))
		return (0);
	while (++i < 3)
		if (first_line[len - 3 + i] < 32 || first_line[len - 3 + i] == 127)
			return (0);
	return (1);
}

void	get_map_info(char *file_name, char **marks, long long *row_num)
{
	int		len;
	int		fd;
	char	buffer[BUFFER_SIZE];
	char	*first_line;

	fd = open(file_name, O_RDONLY);
	read(fd, buffer, BUFFER_SIZE);
	first_line = strdup_term(buffer, "\n");
	len = cf_strlen(first_line);
	if (!validate_first_line(first_line, len))
		map_error();
	else
	{
		*marks = strdup_term(&first_line[len - 3], "\0");
		first_line[len - 3] = '\0';
		*row_num = cf_atol(first_line);
	}
	free(first_line);
	close(fd);
}
