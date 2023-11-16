#include <stdio.h>

void before_main(void) __attribute__((constructor));

/**
 * before_main - Function to be executed before the main function
 */
void before_main(void)
{
	printf("You're beat! and yet, you must allow,
			\nI bore my house upon my back!\n");
}
