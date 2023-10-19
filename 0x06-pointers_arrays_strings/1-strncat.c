/**
 * _strncat - Concatenates two strings,
 * using at most n bytes from src
 * @dest: The destination string
 * @src: The source string to be appended
 * @n: The maximum number of bytes from src to use
 *
 * Return: A pointer to the resulting string dest
 */

char *_strncat(char *dest, char *src, int n)
{
	int dest_len = 0;

	/*Find the length of the destination string*/
	while (dest[dest_len] != '\0')
	{
		dest_len++;
	}

	/*Append at most n bytes from the source string*/
	for (int i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[dest_len + i] = src[i];
	}

	/*Null-terminate the resulting string*/
	dest[dest_len + n] = '\0';

	return (dest);
}
