void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	head;
	int	tail;

	head = 0;
	tail = size - 1;
	while (head < tail)
	{
		ft_swap(&tab[head++], &tab[tail--]);
	}
}
