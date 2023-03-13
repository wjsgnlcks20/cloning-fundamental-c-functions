void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	rev_int_arr(int *arr, int size)
{
	int	head;
	int	tail;

	head = 0;
	tail = size - 1;
	while (head < tail)
		swap(&arr[head++], &arr[tail--]);
}
