#include "../includes/pos.h"

int	is_newline(int x_init, char target, t_pos *dp_idx)
{
	if (target != '\n')
		return (0);
	dp_idx->y++;
	dp_idx->x = x_init;
	return (1);
}
