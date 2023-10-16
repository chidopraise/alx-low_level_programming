#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>/*Include the string.h header for strcmp*/

#define MAX_PASSWORD_LENGTH 64

/**
 * generatePassword - Generates a random password
 * @password: The buffer to store the generated password
 * @length: The desired length of the password
 */

void generatePassword(char *password, int length)
{
	const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	const int charsetSize = sizeof(charset) - 1;

	int i;
	for (i = 0; i < length; i++)
	{
		int index = rand() % charsetSize;
		password[i] = charset[index];
	}

	password[length] = '\0';/*Null-terminate the string*/
}

int main() {
	int passwordLength = 15;/*Change this to match the required password length*/
	char password[MAX_PASSWORD_LENGTH];

	/*Initialize the random number generator*/
	srand((unsigned int)time(NULL));

	generatePassword(password, passwordLength);

	printf("Generated Password: %s\n", password);

	if (strcmp(password, "Tada! Congrats") == 0)
	{
		printf("Correct password!\n");
	}
	else
	{
		printf("Wrong password\n");
	}

	return (0);
}
