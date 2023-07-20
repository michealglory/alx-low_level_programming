#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 *print_all - prints arguements of any type.
 *@format: list of all arguments.
 *
 *Return: void.
 */
void print_all(const char * const format, ...)
{
	unsigned int i;
	va_list args;
	char *sValue, *separator;

	va_start(args, format);

	separator = "";

	i = 0;
	while (format && format[i])
	{
		switch (format[i])
		{
			case 'c':
				printf("%s%c", separator,  va_arg(args, int));
				break;
			case 'i':
				printf("%s%d", separator, va_arg(args, int));
				break;
			case 'f':
				printf("%s%f", separator, va_arg(args, double));
				break;
			case 's':
				sValue = va_arg(args, char *);
				if (sValue == NULL)
					sValue = "(nil)";
				printf("%s%s", separator, sValue);
				break;
			default:
				i++;
				continue;
		}
		separator = ", ";
		i++;
	}

	printf("\n");
	va_end(args);
}
