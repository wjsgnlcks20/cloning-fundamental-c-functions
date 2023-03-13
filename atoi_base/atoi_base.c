int	cf_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

int	validate_base(unsigned char *base)
{
	int		idx;
	int		cache[256];
	char	tok;

	idx = 0;
	while (idx < 256)
		cache[idx++] = 0;
	if (cf_strlen((char *)base) == 1 || *base == '\0')
		return (0);
	while (*base)
	{
		tok = *base;
		if (cache[(int)tok])
			return (0);
		if (tok == '+' || tok == '-' || \
				(tok >= 9 && tok <= 13) || tok == ' ')
			return (0);
		cache[(int)tok]++;
		base++;
	}
	return (1);
}

int	convert_single_digit(char c, char *base, int base_len)
{
	int	digit;

	digit = 0;
	while (digit < base_len)
	{
		if (base[digit] == c)
			return (digit);
		digit++;
	}
	return (-1);
}

int	convert(char *str, char *base)
{
	int	ret;
	int	base_len;
	int	converted_to_int;

	ret = 0;
	base_len = cf_strlen(base);
	while (*str)
	{
		converted_to_int = convert_single_digit(*str, base, base_len);
		if (converted_to_int < 0)
			break ;
		ret = ret * base_len + converted_to_int;
		str++;
	}
	return (ret);
}

int	atoi_base(char *str, char *base)
{
	int	plus_minus;

	plus_minus = 1;
	if (!validate_base((unsigned char *)base))
		return (0);
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			plus_minus *= -1;
		str++;
	}
	return (convert(str, base) * plus_minus);
}
