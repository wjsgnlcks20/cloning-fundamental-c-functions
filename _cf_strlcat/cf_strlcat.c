unsigned int	cf_strlen(char *str)
{
	unsigned int	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

unsigned int	cf_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	s_idx;
	unsigned int	d_len;

	d_len = cf_strlen(dest);
	s_idx = 0;
	if (d_len > size)
		return (size + cf_strlen(src));
	while (src[s_idx] && (d_len + s_idx + 1) < size)
	{
		dest[d_len + s_idx] = src[s_idx];
		s_idx++;
	}
	dest[d_len + s_idx] = '\0';
	return (d_len + cf_strlen(src));
}
