#include <unistd.h>

unsigned int	get_absolute_and_write_minus_or_zero(int nb)
{
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	else if (nb == 0)
		write(1, "0", 1);
	return (nb);
}

void	print_recursively(unsigned int u_nb, long long divider)
{	
	if (u_nb < divider)
		return ;
	print_recursively(u_nb, divider * 10);
	write(1, &"0123456789"[u_nb / divider % 10], 1);
}

void	ft_putnbr(int nb)
{
	unsigned int	u_nb;

	u_nb = get_absolute_and_write_minus_or_zero(nb);
	print_recursively(u_nb, 1L);
}
