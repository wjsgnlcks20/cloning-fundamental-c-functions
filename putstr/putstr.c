#include <unistd.h>

int	cf_strlen(char *str)
{
	int	idx;

	idx = 0;
	while (*str++)
		idx++;
	return (idx);
}

void	putstr(char *str)
{
	write(1, str, cf_strlen(str));
}
