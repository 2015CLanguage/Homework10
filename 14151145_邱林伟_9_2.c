#include<stdio.h>
struct Day
{
	int year;
	int month;
	int date;
};

int sumdays(struct Day days);
void main()
{
	struct Day day;
	printf("请输入年月日:\n");
	scanf("%d,%d,%d",&day.year,&day.month,&day.date);
	printf("这是本年的第%d天\n",sumdays(day));
}
    

int sumdays(struct Day days)
{
	int day1[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int	day2[12]={31,29,31,30,31,30,31,31,30,31,30,31};
	int i,sum=0;
    if(days.year%4!=0&&days.year%400!=0)
	{
		for(i=0;i<days.month-1;i++)
		{sum=sum+day1[i];}
		sum=sum+days.date;}
    else
	{
        for(i=0;i<days.month-1;i++)
		{sum=sum+day2[i];}
		sum=sum+days.date;}
	return sum;
}
