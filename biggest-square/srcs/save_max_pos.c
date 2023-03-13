#include "../includes/pos.h"

void	save_max_pos(t_pos *max_pos, int cur_value, t_pos cur)
{
	if (max_pos->value >= cur_value)
		return ;
	max_pos->value = cur_value;
	max_pos->y = cur.y;
	max_pos->x = cur.x;
}
