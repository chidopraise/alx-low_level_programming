/**
 *  _memcpy - function copies @n bytes from memory areac
 *  @src to memory area @dest
 *
 * @n: function copies
 *
 * @src: bytes from memory area
 *
 * @dest: to memory area
 *
 * Return: a pointer to @dest
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int g = 0;
	while (g < n)
	{
		dest[g] = src[g];
		g++;
	}
	return (dest);
}
