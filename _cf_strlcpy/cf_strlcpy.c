unsigned int	cf_strlen(char *src)
{
	unsigned int	len;

	len = 0;
	while (src[len])
		len++;
	return (len);
}

unsigned int	cf_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	idx;
	unsigned int	s_len;

	idx = 0;
	s_len = cf_strlen(src);
	while ((idx++ + 1 < size) && *src)
		*dest++ = *src++;
	if (size)
		*dest = '\0';
	return (s_len);
}
