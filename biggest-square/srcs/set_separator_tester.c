void	set_separator_tester(char *charset, int *tester)
{
	int	idx;

	idx = -1;
	while (++idx < 256)
		tester[idx] = 0;
	while (*charset)
		tester[(unsigned char)*charset++] = 1;
}
