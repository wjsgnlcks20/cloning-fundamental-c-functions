#include <unistd.h>

int	get_strlen(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		idx++;
	}
	return (idx);
}

void	ft_putstr(char *str)
{
	write(1, str, get_strlen(str));
}
