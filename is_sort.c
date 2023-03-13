int is_sort(int *tab, int length, int (*f)(int, int))
{	
	int			idx;
	long long	order;
	long long	current;

	idx = 0;
	order = 0LL;
	while (idx + 1 < length)
	{
		if (order == 0)
			order = f(tab[idx], tab[idx + 1]);
		current = f(tab[idx], tab[idx + 1]);
		if (order * current < 0)
			return (0);
		idx++;
	}
	return (1);
}
