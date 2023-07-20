#ifndef MAIN_H
#define MAIN_H

int _putchar(char c);
int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);
void print_char(va_list args, const char *separator);
void print_integer(va_list args, const char *separator);
void print_float(va_list args, const char *separator);
void print_string(va_list args, const char *separator);

#endif /* MAIN_H */
