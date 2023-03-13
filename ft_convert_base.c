#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);
int	ft_strlen(char *str);
int	validate_base(unsigned char *base);

unsigned int	get_absolute_and_add_minus(int nbr, char **init)
{
	if (nbr < 0)
	{
		**init = '-';
		*init += 1;
		nbr *= -1;
	}
	return (nbr);
}

char	*ft_convert_nbr_by(int nbr, char *base)
{
	unsigned int	u_nbr;
	long long		divider;
	int				base_len;
	char			*ret;
	char			*init;

	init = (char *)malloc(sizeof(char) * 35);
	ret = init;
	u_nbr = get_absolute_and_add_minus(nbr, &init);
	base_len = ft_strlen(base);
	divider = 1;
	while (divider <= u_nbr)
		divider *= base_len;
	divider /= base_len;
	if (divider == 0)
		*init++ = base[0];
	while (divider)
	{
		*init++ = base[u_nbr / divider % base_len];
		divider /= base_len;
	}
	*init = '\0';
	return (ret);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	if (!validate_base((unsigned char *)base_from) \
			|| !validate_base((unsigned char *)base_to))
		return (NULL);
	return (ft_convert_nbr_by(ft_atoi_base(nbr, base_from), base_to));
}
