/**
 * _strncpy - Copies at most n bytes of a string from src to dest
 * @dest: The destination string
 * @src: The source string to be copied
 * @n: The maximum number of bytes to copy
 *
 * Return: A pointer to the resulting string dest
 */

char *_strncpy(char *dest, const char *src, int n)
{
	int i;

	/*Copy at most n bytes from src to dest*/
	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}

	/*Null-terminate the resulting string*/
	for (; i < n; i++)
	{
		dest[i] = '\0';
	}

	return (dest);
}
