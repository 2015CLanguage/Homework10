#include<stdio.h>
int main(void)
{	int day_tab[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
		int year,month,day,i,days=0;
		struct Date
	{
		int year;
		int month;
		int day;
	}date;

	printf("请输入日期：\n");
	scanf("%d%d%d",&date.year,&date.month,&date.day);
	
	
		for(i=1;i<date.month;i++)
		{
			days=days+day_tab[i];
			days=days+date.day;}
		if((date.year%4==0&&date.year%100!=0||date.year%400==0)&&month>=3)
			days+=1;
	
	printf("这一天是该年的第%d天",days);

	return 0;
	}
