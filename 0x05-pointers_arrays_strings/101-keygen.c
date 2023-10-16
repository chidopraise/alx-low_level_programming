#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * generatePassword - Generates a random password
 * @password: The buffer to store the generated password
 * @length: The desired length of the password
 */

void generatePassword(char *password, int length)
{
	const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	const int charsetSize = sizeof(charset) - 1;

	/*Initialize the random number generator*/
	srand((unsigned int)time(NULL));

	for (int i = 0; i < length; i++)
	{
		int index = rand() % charsetSize;
		password[i] = charset[index];
	}

	password[length] = '\0';/*Null-terminate the string*/
}

int main()
{
	int passwordLength = 12;/*Change this to match your desired password length*/
	char password[passwordLength + 1];

	generatePassword(password, passwordLength);

	printf("Generated Password: %s\n", password);

	return (0);
}
