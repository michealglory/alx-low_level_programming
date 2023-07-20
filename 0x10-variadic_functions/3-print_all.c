#include <stdio.h>
#include <stdarg.h>

/**
 * print_all - Prints anything based on the format provided.
 * @format: A list of types of arguments passed to the function.
 *          'c': char
 *          'i': integer
 *          'f': float
 *          's': char * (if the string is NULL, print (nil) instead)
 */
void print_all(const char * const format, ...)
{
	va_list args;
	char *separator = "";
	unsigned int i = 0;
	char *str_arg;

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == 'c')
		{
			printf("%s%c", separator, va_arg(args, int));
		}
		else if (format[i] == 'i')
		{
			printf("%s%d", separator, va_arg(args, int));
		}
		else if (format[i] == 'f')
		{
			printf("%s%f", separator, va_arg(args, double));
		}
		else if (format[i] == 's')
		{
			str_arg = va_arg(args, char *);
			if (str_arg == NULL)
				str_arg = "(nil)";
			printf("%s%s", separator, str_arg);
		}

		separator = ", ";
		i++;
	}

	printf("\n");
	va_end(args);
}

