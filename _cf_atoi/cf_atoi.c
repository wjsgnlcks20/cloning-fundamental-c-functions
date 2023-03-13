int	cf_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

int	is_numeric(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	cf_atoi(char *str)
{
	int	ret;
	int	positive;

	ret = 0;
	positive = 1;
	while (cf_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			positive *= -1;
		str++;
	}
	while (is_numeric(*str))
	{
		ret = ret * 10 + ((*str) - '0');
		str++;
	}
	return (ret * positive);
}
