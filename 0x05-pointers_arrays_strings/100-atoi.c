#include "main.h"

/**
 * _atoi - Converts a string to an integer
 * @s: The string to convert
 *
 * Return: The integer value of the string
 */

int _atoi(char *s)
{
	int result = 0;
	int sign = 1;
	int i = 0;

	/*Handle leading signs*/
	if (s[0] == '-')
	{
		sign = -1;
		i++;
	}
	else if (s[0] == '+')
	{
		i++;
	}

	/*Convert the string to an integer*/
	while (s[i] != '\0')
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result = (result * 10) + (s[i] - '0');
		}
		else
		{
			break;/*Stop at the first non-numeric character*/
		}
		i++;
	}

	return (result * sign);
}
