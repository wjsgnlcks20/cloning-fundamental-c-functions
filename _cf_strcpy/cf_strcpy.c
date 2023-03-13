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
