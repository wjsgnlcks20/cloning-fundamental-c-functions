#include <stdlib.h>

int	cf_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

char	*cf_strdup(char *str)
{
	char	*ret;
	char	*init;

	init = (char *)malloc(sizeof(char) * (cf_strlen(str) + 1));
	ret = init;
	while (*str)
		*init++ = *str++;
	*init = '\0';
	return (ret);
}

void	set_separator_tester(unsigned char *charset, int *tester)
{
	int	idx;

	idx = -1;
	while (++idx < 256)
		tester[idx] = 0;
	while (*charset)
		tester[*charset++] = 1;
}

int	str_plant_nul_divider(char *str, char *charset)
{
	int	tester[256];
	int	flag;
	int	word_cnt;

	word_cnt = 0;
	flag = 0;
	set_separator_tester((unsigned char *)charset, tester);
	while (*str)
	{
		if (tester[(unsigned char)*str])
		{
			*str = '\0';
			flag = 0;
		}
		else if (flag == 0)
		{
			word_cnt++;
			flag = 1;
		}
		str++;
	}
	return (word_cnt);
}

char	**split(char *str, char *charset)
{
	char	**init;
	char	**ret;
	char	*my_str;
	int		word_cnt;
	int		idx;

	idx = -1;
	my_str = cf_strdup(str);
	word_cnt = str_plant_nul_divider(my_str, charset);
	init = (char **)malloc(sizeof(char *) * (word_cnt + 1));
	ret = init;
	while (++idx < word_cnt)
	{
		while (*my_str == '\0')
			my_str++;
		*init++ = cf_strdup(my_str);
		my_str += cf_strlen(my_str);
	}
	*init = (void *)0;
	return (ret);
}
