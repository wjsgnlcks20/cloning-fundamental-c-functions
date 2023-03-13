void	set_separator_tester(char *charset, int *tester);

int	strlen_term(char *str, char *charset)
{
	int	len;
	int	terms[256];

	set_separator_tester(charset, terms);
	len = 0;
	while (str[len] && !terms[(int)str[len]])
		len++;
	return (len);
}
