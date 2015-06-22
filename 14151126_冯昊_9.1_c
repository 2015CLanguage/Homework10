#include<stdio.h>
struct
{
	int year;
	int month;
	int day;
}
date;

int main()
{
	int i, days;
	int day_tab[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	printf("请输入年，月，日：");
	scanf_s("%d,%d,%d", &date.year, &date.month, &date.day);
	days = 0;
	for (i = 1; i<date.month; i++)
		days = days + day_tab[i];
	days = days + date.day;
	if ((date.year % 4 == 0 && date.year % 100 != 0 || date.year % 400 == 0) && date.month >= 3)
		days = days + 1;
	printf("%d月%d日，是%d年的第%d天\n", date.month, date.day, date.year, days);
	return 0;
}
