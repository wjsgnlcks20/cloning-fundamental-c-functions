#include "../includes/pos.h"

void	dp_init_pos(t_pos *pos)
{
	pos->value = 0;
	pos->c_size = -1;
	pos->x = 0;
	pos->y = 0;
}

void	max_init_pos(t_pos *pos)
{
	pos->value = 0;
	pos->c_size = -1;
	pos->x = -1;
	pos->y = -1;
}

void	error_init_pos(t_pos *pos)
{
	pos->value = 0;
	pos->x = -2;
	pos->y = -2;
}

int	is_error_pos(t_pos pos)
{
	if (pos.x == pos.y && pos.x == -2)
		return (1);
	return (0);
}
