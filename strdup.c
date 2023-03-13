#include <stdlib.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

char	*ft_strcpy(char *dest, char *src)
{
	char	*ret;

	if (dest == (void *)0)
		return (dest);
	ret = dest;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (ret);
}

char	*ft_strdup(char *src)
{
	char	*dest;	

	dest = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	return (ft_strcpy(dest, src));
}
