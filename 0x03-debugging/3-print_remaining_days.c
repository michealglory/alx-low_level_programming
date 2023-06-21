#include "main.h"

/**
 * print_remaining_days - takes a date and prints how many days are
 * left in the year, taking leap years into account
 * @month: month in number format
 * @day: day of month
 * @year: year
 *
 * Return: void
 */
void print_remaining_days(int month, int day, int year)
{
	int is_leap_year;
	int max_days_in_month;
	int day_of_year;
	int remaining_days;

	is_leap_year = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

	if (month == 2)
	{
		max_days_in_month = is_leap_year ? 29 : 28;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		max_days_in_month = 30;
	}
	else
	{
		max_days_in_month = 31;
	}

	if (day < 1 || day > max_days_in_month)
	{
		printf("Invalid date: %02d/%02d/%04d\n", month, day, year);
		return;
	}

	day_of_year = convert_day(month, day);

	if (is_leap_year && month > 2)
	{
		day_of_year++;
	}

	remaining_days = is_leap_year ? 366 - day_of_year : 365 - day_of_year;

	printf("Day of the year: %d\n", day_of_year);
	printf("Remaining days: %d\n", remaining_days);
}

