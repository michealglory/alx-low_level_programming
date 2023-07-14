#ifndef MAIN_H
#define MAIN_H

int _putchar(char c);
void *malloc_checked(unsigned int b);
char *string_nconcat(char *s1, char *s2, unsigned int n);
void *_calloc(unsigned int nmemb, unsigned int size);
int *array_range(int min, int max);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int is_positive_number(char *str);
int multiply(int num1, int num2);
void print_result(char *result, int length);
char *multiply_strings(char n, char *num, int num_length, char *result, int result_index);
int is_digit(char **args);
void initialize_string(char *str, int length);

#endif /* MAIN_H */
