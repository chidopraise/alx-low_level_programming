/**
 * cap_string - Capitalizes all words in a string
 * @str: The input string
 *
 * Return: A pointer to the modified string
 */

char *cap_string(char *str) {
	int i = 0;
	int capitalize = 1;

	while (str[i] != '\0')
	{
		char current = str[i];
		if (current == ' ' || current == '\t' || current == '\n' || current == ',' || current == ';' || current == '.' || current == '!' || current == '?' || current == '"' || current == '(' || current == ')' || current == '{' || current == '}' || i == 0)
		{
			capitalize = 1;
		}
		else if ((current >= 'a' && current <= 'z') && capitalize)
		{
			str[i] = current - 'a' + 'A';
			capitalize = 0;
		}
		else
		{
			capitalize = 0;
		}
		i++;
	}

	return (str);
}
