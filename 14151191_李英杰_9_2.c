#include<stdio.h>
struct Dates
	{
		int year;
		int month;
		int date;
	};
int day(struct Dates d);
int main()
{
	struct Dates daytime;
	struct Dates *p=&daytime;
	int days;
	printf("please input date\n");
	scanf("%d%d%d",&p->year,&p->month,&p->date);
	days=day(*p);
	printf("%d.%d is the %dth in %d\n",p->month,p->date,days,p->year);
	return 0;
}
int day(struct Dates d)
{
	int i,days;
	int daylist[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	for(i=1,days=0;i<d.month;i++)
		days+=daylist[i];
	days+=d.date;
	if(((d.year%400==0)||((d.year%4==0)&&(d.year%100!=0)))&&(d.month>2))
		days+=1;
	return days;
}
