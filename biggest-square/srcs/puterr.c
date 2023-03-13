#include <unistd.h>

int	cf_strlen(char *str);

void	puterr(char *str)
{
	write(2, str, cf_strlen(str));
}
