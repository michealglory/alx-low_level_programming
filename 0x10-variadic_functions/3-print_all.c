#include <stdio.h>
#include <stdarg.h>

/**
 * print_all - Prints anything.
 * @format: List of all arguments passed to the function.
 */
void print_all(const char * const format, ...)
{
	va_list args;
	const char *separator = "";
	unsigned int i = 0;
	char *s;

	va_start(args, format);

	while (format && format[i])
	{
		switch (format[i])
		{
			case 'c':
				printf("%s%c", separator, va_arg(args, int));
				break;
			case 'i':
				printf("%s%d", separator, va_arg(args, int));
				break;
			case 'f':
				printf("%s%f", separator, va_arg(args, double));
				break;
			case 's':
				s = va_arg(args, char *);
				if (s == NULL)
					s = "(nil)";
				printf("%s%s", separator, s);
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

