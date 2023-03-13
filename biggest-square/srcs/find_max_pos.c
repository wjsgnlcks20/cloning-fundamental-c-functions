#include "../includes/bsq.h"

int	min_dp(int *dp, int idx, int save)
{
	if (idx - 1 < 0)
		return (0);
	return (min_tri(dp[idx], dp[idx - 1], save));
}

void	crlf_pos(t_pos *dp_idx)
{
	dp_idx->y++;
	dp_idx->x = 0;
}

void	update_dp(int *save, int *dp, t_pos *dp_idx, t_pos *max)
{
	save[1] = dp[dp_idx->x];
	dp[dp_idx->x] = min_dp(dp, dp_idx->x, save[0]) + 1;
	if (max->value < dp[dp_idx->x])
	{
		max->value = dp[dp_idx->x];
		max->y = dp_idx->y;
		max->x = dp_idx->x;
	}
	dp_idx->x++;
	save[0] = save[1];
}

long long	set_max_pos_dp(int fd, int *dp, char *marks, t_pos *max)
{
	int		bytes;
	int		idx;
	int		save[2];
	char	buffer[BUFFER_SIZE];
	t_pos	dp_idx;

	save[0] = 0;
	bytes = read_first_line(fd, buffer, &idx, &dp_idx);
	while (++idx < bytes)
	{
		if (buffer[idx] == '\n' && dp_idx.x == max->c_size)
			crlf_pos(&dp_idx);
		else if (dp_idx.x >= max->c_size)
			return (-1);
		else if (buffer[idx] == marks[1])
			dp[dp_idx.x++] = 0;
		else if (buffer[idx] == marks[0])
			update_dp(save, dp, &dp_idx, max);
		else
			return (-1);
		read_next_if_buffer_end(fd, &idx, buffer, &bytes);
	}
	return (dp_idx.y);
}

t_pos	find_max_pos(char *file_name, char *marks, long long row_num)
{
	int			fd;
	long long	newline_cnt;
	int			*dp;
	t_pos		max_pos;

	max_init_pos(&max_pos);
	fd = open(file_name, O_RDONLY);
	dp = create_dp(file_name, &max_pos);
	newline_cnt = set_max_pos_dp(fd, dp, marks, &max_pos);
	if (newline_cnt != row_num || newline_cnt < 0 || max_pos.c_size == 0)
	{
		map_error();
		error_init_pos(&max_pos);
	}
	free(dp);
	close(fd);
	return (max_pos);
}
