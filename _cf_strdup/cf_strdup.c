#include <stdlib.h>

unsigned int	cf_strlen(char *str)
{
	unsigned int	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

char	*cf_strcpy(char *dest, char *src)
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

char	*cf_strdup(char *src)
{
	char	*dest;	

	dest = (char *)malloc(sizeof(char) * (cf_strlen(src) + 1));
	return (cf_strcpy(dest, src));
}
