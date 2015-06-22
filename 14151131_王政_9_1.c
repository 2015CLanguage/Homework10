#include<stdio.h>
struct Date
{
	int year;
	int month;
	int day;
};
struct Date date;
int main()
{
	printf("请输入具体年月日:");
	scanf("%d.%d.%d",&date.year,&date.month,&date.day);
	int i,s,x;
	int m[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	if(date.month==1)
	{
		x=date.day;
	}
	else if(date.month==2)
	{
		x=31+date.day;
	}
	else
	{
		s=0;
		for(i=0;i<date.month-1;i++)
		{
			s=s+m[i];
		}
		if(date.year%400==0||(date.year%4==0&&date.year%100!=0))
		{
			x=s+date.day+1;
		}
		else
		{
			x=s+date.day;
		}
	}
        printf("该日是该年的第%d天",x);
	return 0;
}
