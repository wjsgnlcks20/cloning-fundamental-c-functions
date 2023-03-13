#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

int	getmax(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	get_init_size(int size, char **strs, char *sep)
{
	int	total_len;
	int	sp_len;
	int	idx;

	idx = 0;
	total_len = 0;
	sp_len = ft_strlen(sep);
	while (idx < size)
		total_len += ft_strlen(strs[idx++]);
	return (total_len + sp_len * getmax(size - 1, 0) + 1);
}

char	*m_strcpy(char *dest, char *src1, char *src2)
{
	while (*src1)
		*dest++ = *src1++;
	while (*src2)
		*dest++ = *src2++;
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*ret;	
	char	*init;	
	int		idx;
	int		sep_len;

	init = (char *)malloc(sizeof(char) * get_init_size(size, strs, sep));
	ret = init;
	sep_len = ft_strlen(sep);
	idx = 0;
	while (idx < size)
	{
		if (idx + 1 == size)
			sep = "";
		init = m_strcpy(init, strs[idx], sep);
		idx++;
	}
	*init = '\0';
	return (ret);
}
