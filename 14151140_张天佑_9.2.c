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
	if ((date.year % 4 == 0 && date.year % 100 != 0) || date.year % 400 == 0)           //判断是否为闰年
	{
		for (i = 1; i < date.month; i++)                                  //累加所在月之前天数
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
void main()
{
	printf("输入日期:\n");
	scanf_s("%d.%d.%d", &date.year, &date.month, &date.day);                         //调用函数输出
	printf("%d年%d月%d日是那一年的第%d天.\n", date.year, date.month, date.day, days(date));
}
