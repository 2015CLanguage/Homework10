#include<stdio.h>
struct Day
{
	int year;
	int month;
	int date;
};

void main()
{
	struct Day day;
	int days1[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int	days2[12]={31,29,31,30,31,30,31,31,30,31,30,31};
	int i,sum=0;
	printf("请输入年月日:\n");
	scanf("%d,%d,%d",&day.year,&day.month,&day.date);
	if(day.year%4!=0&&day.year%400!=0)
	{
		for(i=0;i<day.month-1;i++)
		{sum=sum+days1[i];}
		sum=sum+day.date;}
    else
	{
        for(i=0;i<day.month-1;i++)
		{sum=sum+days2[i];}
		sum=sum+day.date;}
	printf("这是本年的第%d天\n",sum);
}
