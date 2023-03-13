#include <stdlib.h>

int atoi_base(char *str, char *base);
int	cf_strlen(char *str);
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

char	*convert_nbr_by(int nbr, char *base)
{
	unsigned int	u_nbr;
	long long		divider;
	int				base_len;
	char			*ret;
	char			*init;

	init = (char *)malloc(sizeof(char) * 35);
	ret = init;
	u_nbr = get_absolute_and_add_minus(nbr, &init);
	base_len = cf_strlen(base);
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

char	*convert_base(char *nbr, char *base_from, char *base_to)
{
	if (!validate_base((unsigned char *)base_from) \
			|| !validate_base((unsigned char *)base_to))
		return (NULL);
	return (convert_nbr_by(atoi_base(nbr, base_from), base_to));
}
