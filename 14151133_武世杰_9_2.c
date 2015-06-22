#include "stdio.h"
struct Date
{
	int year;
	int month;
	int day;
}date;
int days(struct Date date)
{
	int tab1[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }, tab2[13] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int i;
	if ((date.year % 4 == 0 && date.year % 100 != 0) || date.year % 400 == 0)
	{
		for (i = 1; i < date.month; i++)
		{
			date.day += tab2[i];
		}
	}
	else
	{
		for (i = 1; i < date.month; i++)
		{
			date.day += tab1[i];
		}
	}
	return(date.day);
}
int main()
{
	printf("输入日期:\n");
	scanf_s("%d.%d.%d", &date.year, &date.month, &date.day);
	printf("%d年%d月%d日是那一年的第%d天.\n", date.year, date.month, date.day, days(date));
	return 0
}
