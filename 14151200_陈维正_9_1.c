#include<stdio.h> 
int main()
{
struct Date
	{	
	int month;
	int day;
	int year;
	}date;
printf("按照月，日，年输入日期:");
scanf("%d%d%d",&date.month,&date.day,&date.year);
printf("%d年%d月%d日是该年的:",date.year,date.month,date.day);
int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
if(date.year%100!=0&&date.year%4==0)
	a[1]=29;
if(date.year%400==0)
	a[1]=29;
int i,b=0;
for(i=0;i<=date.month-2;i++)
	b=b+a[i];
printf("第%d天",b+date.day);
return 0;
}
