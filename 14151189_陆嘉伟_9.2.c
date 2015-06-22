#include<stdio.h>
struct
{
int year;
int month;
int day;
}date;

int main()
{
int days(int year,int month,int day);
int days1;
printf("输入年，月，日:");
scanf("%d %d %d",&date.year,&date.month,&date.day);
days1=days(date.year,date.month,date.day);
printf("是第%d天",days1);
return 0;
}

int days(int year,int month,int day)
{
int i,days1=0;
int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
for(i=0;i<month-1;i++)
	days1=days1+a[i];
days1=days1+day;
if(date.month>=3)
	if(year%4==0&&year%100!=0||year%400==0)
		days1=days1+1;
return(days1);
}
