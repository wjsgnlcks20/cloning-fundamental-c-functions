void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	set_pivot(int *tab, int start, int end)
{
	int	pivot;
	int	head;
	int	tail;

	pivot = start;
	head = start;
	tail = start + 1;
	while (tail <= end)
	{
		if (tab[pivot] > tab[tail])
		{
			swap(&tab[++head], &tab[tail]);
		}
		tail++;
	}
	swap(&tab[pivot], &tab[head]);
	return (head);
}

void	quick_sort(int *tab, int start, int end)
{
	int	pivot;

	if (start > end)
		return ;
	pivot = set_pivot(tab, start, end);
	quick_sort(tab, start, pivot - 1);
	quick_sort(tab, pivot + 1, end);
}

void	ft_sort_int_tab(int *tab, const int size)
{
	quick_sort(tab, 0, size - 1);
}
