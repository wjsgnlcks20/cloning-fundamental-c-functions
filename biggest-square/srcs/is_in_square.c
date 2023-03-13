#include "../includes/pos.h"

int	is_in_square(t_pos cur, t_pos max_pos)
{
	long long	up_left_x;
	long long	up_left_y;

	up_left_x = max_pos.x - max_pos.value + 1;
	up_left_y = max_pos.y - max_pos.value + 1;
	if ((up_left_x <= cur.x && cur.x <= max_pos.x) \
		&& (up_left_y <= cur.y && cur.y <= max_pos.y))
		return (1);
	return (0);
}
