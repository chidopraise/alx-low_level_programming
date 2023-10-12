/**
 * _isalpha - Checks if a character is alphabetic.
 * @c: The character to check.
 *
 * Return: 1 if c is an alphabetic character, 0 otherwise.
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1); /* c is an alphabetic character */
	}
	else
	{
		return (0); /* c is not an alphabetic character */
	}
}
