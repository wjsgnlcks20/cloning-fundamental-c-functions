#include <stdlib.h>

int		strlen_term(char *str, char *charset);
char	*strcpy_term(char *dest, char *src, char *charset);

char	*strdup_term(char *src, char *charset)
{
	char	*dest;

	dest = (char *)malloc(sizeof(char) * (strlen_term(src, charset) + 1));
	return (strcpy_term(dest, src, charset));
}
