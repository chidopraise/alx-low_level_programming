/**
 * _strcat - Concatenates two strings
 * @dest: The destination string
 * @src: The source string to append
 *
 * Return: A pointer to the resulting string dest
 */

char *_strcat(char *dest, char *src)
{
	int dest_len = 0;
	int src_len = 0;

	while (dest[dest_len] != '\0')
	{
		dest_len++;
	}

	while (src[src_len] != '\0')
	{
		dest[dest_len + src_len] = src[src_len];
		src_len++;
	}

	dest[dest_len + src_len] = '\0';

	return (dest);
}
