char	*ft_strncat(char *dest, char *src, unsigned int nb)
{	
	char			*ret;

	ret = dest;
	while (*dest)
		dest++;
	while (nb && *src)
	{
		*dest++ = *src++;
		nb--;
	}
	*dest = '\0';
	return (ret);
}
