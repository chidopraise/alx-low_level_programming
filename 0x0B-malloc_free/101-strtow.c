#include <stdlib.h>

/**
 * is_space - Check if a character is a whitespace character.
 * @c: The character to check.
 *
 * Return: 1 if the character is a whitespace character, 0 otherwise.
 */
int is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

/**
 * count_words - Count the number of words in a string.
 * @str: The string to count words in.
 *
 * Return: The number of words in the string.
 */
int count_words(char *str)
{
	int word_count = 0;
	int in_word = 0;

	while (*str)
	{
		if (!is_space(*str))
		{
			if (!in_word)
			{
				word_count++;
				in_word = 1;
			}
		}
		else
		{
			in_word = 0;
		}
		str++;
	}

	return word_count;
}

/**
 * extract_words - Extract words from a string.
 * @str: The string to extract words from.
 * @words: An array to store the extracted words.
 *
 * Return: 1 on success, 0 on failure.
 */
int extract_words(char *str, char **words)
{
	int i = 0, j, len, in_word = 0, word_count = count_words(str);

	while (i < word_count)
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
				return 0;
			}

			for (j = 0; j < len; j++)
				words[i][j] = str[j];

			words[i][j] = '\0';
			str += len;
			i++;
		}
		else
		{
			str++;
		}
	}
	return 1;
}

/**
 * strtow - Split a string into words.
 * @str: The string to split into words.
 *
 * Return: An array of strings (words), or NULL on failure.
 */
char **strtow(char *str)
{
	int word_count = count_words(str);
	if (word_count == 0)
		return NULL;

	char **words = malloc((word_count + 1) * sizeof(char *));
	if (words == NULL)
		return NULL;

	words[word_count] = NULL;
	if (!extract_words(str, words))
	{
		free(words);
		return NULL;
	}

	return words;
}
