#include <unistd.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

int	validate_base(unsigned char *base)
{
	int	i;
	int	cache[256];

	i = 0;
	while (i < 256)
		cache[i++] = 0;
	if (ft_strlen((char *)base) == 1 || *base == '\0')
		return (0);
	while (*base)
	{
		if (cache[(int)*base])
			return (0);
		if (*base == '+' || *base == '-')
			return (0);
		cache[(int)*base]++;
		base++;
	}
	return (1);
}

unsigned int	get_absolute_and_print_minus(int nbr)
{
	if (nbr < 0)
	{	
		write(1, "-", 1);
		nbr *= -1;
	}
	return (nbr);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	u_nbr;
	long long		divider;
	int				base_len;

	if (!validate_base((unsigned char *)base))
		return ;
	u_nbr = get_absolute_and_print_minus(nbr);
	base_len = ft_strlen(base);
	divider = 1;
	while (divider <= u_nbr)
		divider *= base_len;
	divider /= base_len;
	if (divider == 0)
	{
		write(1, &base[0], 1);
		return ;
	}
	while (divider)
	{
		write(1, &base[u_nbr / divider % base_len], 1);
		divider /= base_len;
	}
}
