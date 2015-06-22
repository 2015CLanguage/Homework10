#include<stdio.h>
	struct Date
	{
		int year;
		int month;
		int day;
	}date;
	int days(int year,int month,int day);
int main(void)
{
	int day_sum;
	printf("请输入日期：\n");
	scanf("%d%d%d",&date.year,&date.month,&date.day);
	day_sum=days(date.year,date.month,date.day);
	printf("这一天是该年的第%d天",days);
	return 0;
	}
int days(int year,int month,int day)
{
	int day_sum=0,i;
	int day_tab[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	day_sum=0;
	for(i=1;i<date.month;i++)
		{
			day_sum=day_sum+day_tab[i];
		}	day_sum=day_sum+day;
		if((year%4==0&&year%100!=0|year%400==0)&&month>=3)
			day_sum+=1;
		return(day_sum);
}
