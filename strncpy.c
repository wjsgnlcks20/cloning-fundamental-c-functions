char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char	*ret;

	if (dest == (void *)0)
		return (dest);
	ret = dest;
	while (n && *src)
	{
		*dest++ = *src++;
		n--;
	}
	while (n--)
		*dest++ = '\0';
	return (ret);
}
