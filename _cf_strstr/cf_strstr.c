#define STRING_MAX_LEN 2100

int	cf_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

int	count_equal_char(char *dest, char *src)
{
	int	idx;

	idx = 0;
	while (dest[idx] && (dest[idx] == src[idx]))
		idx++;
	return (idx);
}

void	set_kmp(int *kmp_table, char *str)
{
	int	len;
	int	i;
	int	j;

	i = 0;
	j = 1;
	len = cf_strlen(str);
	kmp_table[0] = -1;
	while (j < len)
	{
		while (str[i] != str[j] && i > 0)
			i = kmp_table[i];
		if (str[i] == str[j])
			kmp_table[j + 1] = ++i;
		j++;
	}
}

char	*cf_strstr(char *str, char *to_find)
{
	int	f_len;
	int	k_idx;
	int	equal_cnt;
	int	kmp_table[STRING_MAX_LEN];

	if (cf_strlen(to_find) == 0)
		return (str);
	k_idx = 0;
	while (k_idx < STRING_MAX_LEN)
		kmp_table[k_idx++] = 0;
	set_kmp(kmp_table, to_find);
	equal_cnt = 0;
	f_len = cf_strlen(to_find);
	while (*str)
	{
		equal_cnt = count_equal_char(str, to_find);
		if (equal_cnt == f_len)
			return (str);
		str += equal_cnt - kmp_table[equal_cnt];
	}
	return ((void *)0);
}
