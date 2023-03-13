int	is_whitespace(char c);
int	is_numeric(char c);

long long	cf_atol(char *str)
{
	long long	ret;
	int			positive;

	ret = 0LL;
	positive = 1;
	while (is_whitespace(*str))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			positive *= -1;
		str++;
	}
	while (is_numeric(*str))
	{
		ret = ret * 10LL + ((*str) - '0');
		str++;
	}
	return (ret * positive);
}
