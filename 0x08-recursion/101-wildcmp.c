#include "main.h"

/**
 * wildcmp - Compares two strings with wildcard character '*'
 * @s1: First string
 * @s2: Second string with wildcard character '*'
 *
 * Return: 1 if the strings can be considered identical, 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
	if (*s2 == '*')
	{
		if (*(s2 + 1) == '*')
			return (wildcmp(s1, s2 + 1));
		if (wildcmp(s1, s2 + 1))
			return (1);
		return (wildcmp(s1 + 1, s2));
	}

	if (*s1 == *s2)
	{
		if (*s1 == '\0' && *s2 == '\0')
			return (1);
		return (wildcmp(s1 + 1, s2 + 1));
	}
	return (0);
}
