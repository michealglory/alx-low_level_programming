#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_all - Prints data based on the given format string.
 *
 * @format: A string containing format specifiers.
 *          c: char
 *          i: integer
 *          f: float
 *          s: char* (if the string is NULL, print (nil) instead)
 *          Any other character should be ignored.
 *
 * Return: Always void.
 */
void print_all(const char * const format, ...)
{
	va_list args;
	int i = 0;
	char *str;

	va_start(args, format);

	while (format && format[i])
	{
		if (i > 0)
			printf(", ");

		switch (format[i])
		{
			case 'c':
				printf("%c", va_arg(args, int));
				break;
			case 'i':
				printf("%d", va_arg(args, int));
				break;
			case 'f':
				printf("%f", va_arg(args, double));
				break;
			case 's':
				str = va_arg(args, char *);
				if (str == NULL)
					str = "(nil)";
				printf("%s", str);
				break;
			default:
				break;
		}

		i++;
	}

	va_end(args);
	printf("\n");
}

