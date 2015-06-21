#include<stdio.h> 
struct
{
	int y;
	int m;
	int d;
}date;
void main()
{
	int days(int y, int m, int d);
	int day;
	printf("按顺序输入年、月、日:");
	scanf_s("%d%d%d", &date.y, &date.m, &date.d);
	day = days(date.y, date.m, date.d);
	printf("%d年%d月%d日 是该年的第 %d 天\n", date.y, date.m, date.d, day);
}
int days(int y, int m, int d)
{
	int day, i;
	int daytable1[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int daytable2[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	day = d;
	if (date.y % 4 == 0 && date.y % 100 != 0 || date.y % 400 == 0)
	{
		for (i = 0; i<date.m - 1; i++)
			day = day + daytable2[i];
	}
	else
	{
		for (i = 0; i < date.m - 1; i++)
			day = day + daytable1[i];
	}
	return(day);
}
