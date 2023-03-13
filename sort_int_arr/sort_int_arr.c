void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	set_pivot(int *arr, int start, int end)
{
	int	pivot;
	int	head;
	int	tail;

	pivot = start;
	head = start;
	tail = start + 1;
	while (tail <= end)
	{
		if (arr[pivot] > arr[tail])
			swap(&arr[++head], &arr[tail]);
		tail++;
	}
	swap(&arr[pivot], &arr[head]);
	return (head);
}

void	quick_sort(int *arr, int start, int end)
{
	int	pivot;

	if (start > end)
		return ;
	pivot = set_pivot(arr, start, end);
	quick_sort(arr, start, pivot - 1);
	quick_sort(arr, pivot + 1, end);
}

void	sort_int_arr(int *arr, const int size)
{
	quick_sort(arr, 0, size - 1);
}
