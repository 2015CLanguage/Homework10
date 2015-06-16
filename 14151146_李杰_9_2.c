#include<stdio.h>
struct Dates
	{
		int year;
		int month;
		int date;
	}daytime;

int cal(struct Dates daytime)
{
	int daylist[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	int days,i;
	for(i=1,days=0;i<daytime.month;i++)
		days+=daylist[i];
	days+=daytime.date;
	if(((daytime.year%400==0)||((daytime.year%4==0)&&(daytime.year%100!=0)))&&(daytime.month>2))
		days+=1;
	return days;
}
int main()
{
	printf("please input date\n");
	scanf("%d,%d,%d",&daytime.year,&daytime.month,&daytime.date);
	printf("%d\n",cal(daytime));
	return 0;
}
