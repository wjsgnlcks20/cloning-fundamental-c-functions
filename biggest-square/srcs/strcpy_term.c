void	set_separator_tester(char *charset, int *tester);

char	*strcpy_term(char *dest, char *src, char *charset)
{
	int		idx;
	int		terms[256];

	idx = 0;
	set_separator_tester(charset, terms);
	if (dest == (void *)0)
		return (dest);
	while (src[idx] && !terms[(int)src[idx]])
	{
		dest[idx] = src[idx];
		idx++;
	}
	dest[idx] = '\0';
	return (dest);
}
