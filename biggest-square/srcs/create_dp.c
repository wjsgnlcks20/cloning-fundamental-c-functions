#include "../includes/bsq.h"

int	*create_dp(char *file_name, t_pos *max_pos)
{
	int	col;
	int	*dp;
	int	i;

	col = get_line_size(file_name);
	max_pos->c_size = col;
	dp = (int *)malloc(sizeof(int) * (col));
	i = -1;
	while (++i < col)
		dp[i] = 0;
	return (dp);
}
