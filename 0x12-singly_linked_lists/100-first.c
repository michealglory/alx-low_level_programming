#include <stdio.h>

/**
 * first - Function executed automatically before main.
 *
 * This function is executed automatically before the `main` function
 * when the program starts. It is designated with the
 * `__attribute__((constructor))` attribute, which tells the compiler
 * to execute it during the program's initialization phase.
 *
 * The function's purpose is to print the following message:
 * "You're beat! and yet, you must allow,
 * I bore my house upon my back!"
 *
 * This message is printed to the standard output using the `printf`
 * function.
 * The newline character ('\n') is used to introduce a line break in
 * the output.
 */

void __attribute__ ((constructor)) first()
{
	printf("You're beat! and yet, you must allow");
	printf(",\nI bore my house upon my back!\n");
}
