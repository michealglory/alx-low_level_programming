#include "main.h"

/**
 * print_remaining_days - Takes a date and prints how many
 * days are left in the year taking leap years into account
 * @month: month in number format
 * @day: day of month
 * @year: year
 *
 * Return: void
 */
void print_remaining_days(int month, int day, int year)
{
	int is_leap_year = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

	if (is_leap_year && month == 2 && day > 29)
	{
		/* Adjust the day and month to the correct values for leap years*/
		day -= 29;
		month++;
	}

	int remaining_days = is_leap_year ? 366 - day : 365 - day;

	printf("Day of the year: %d\n", day);
	printf("Remaining days: %d\n", remaining_days);
}

