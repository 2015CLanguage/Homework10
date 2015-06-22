#include<stdio.h>
struct
{
int year;
int month;
int day;
}date;
int main()
{
int i,days=0;
int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
printf("输入年，月，日:");
scanf("%d %d %d",&date.year,&date.month,&date.day);
for(i=0;i<date.month-1;i++)
	days=days+a[i];
days=days+date.day;
if(date.month>=3)
	if(date.year%4==0&&date.year%100!=0||date.year%400==0)
		days=days+1;
printf("是第%d天",days);
return 0;
}
