#include <stdlib.h>

/**
 * is_space - Checks if a character is a space, tab, or newline
 * @c: The character to check
 *
 * Return: 1 if it's a space, tab, or newline; 0 otherwise.
 */
int is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

/**
 * count_words - Counts the number of words in a string
 * @str: The input string
 *
 * Return: The number of words in the string.
 */
int count_words(char *str)
{
	int count = 0;
	int in_word = 0;

	while (*str)
	{
		if (is_space(*str))
		{
			in_word = 0;
		}
		else if (in_word == 0)
		{
			in_word = 1;
			count++;
		}
		str++;
	}

	return (count);
}

/**
 * strtow - Splits a string into words
 * @str: The input string
 *
 * Return: A pointer to an array of strings (words) or NULL on failure.
 */
char **strtow(char *str)
{
	int i, j, len = 0, in_word = 0, word_count;
	char **words;

	if (str == NULL || *str == '\0')
		return (NULL);

	word_count = count_words(str);
	words = malloc(sizeof(char *) * (word_count + 1));

	if (words == NULL)
		return (NULL);

	for (i = 0; i < word_count; i++)
	{
		while (is_space(*str))
			str++;

		in_word = 0;
		len = 0;

		while (str[len] && !is_space(str[len]))
		{
			len++;
			in_word = 1;
		}

		if (in_word)
		{
			words[i] = malloc(len + 1);

			if (words[i] == NULL)
			{
				for (j = i - 1; j >= 0; j--)
					free(words[j]);
				free(words);
				return (NULL);
			}

			for (j = 0; j < len; j++)
				words[i][j] = str[j];

			words[i][j] = '\0';
			str += len;
		}
	}

	words[word_count] = NULL;
	return (words);
}
