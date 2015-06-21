#include<stdio.h>
struct Date
	{
		int year;
		int month;
		int date;
	};
int main()
{
	struct Dates daytime;
	struct Dates *p=&daytime;
	int days,i;
	int daylist[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	printf("please input date\n");
	scanf("%d%d%d",&p->year,&p->month,&p->date);
	for(i=1,days=0;i<p->month;i++)
		days=daylist[i]+1;
	days+=p->date;
	if(((p->year%400==0)||((p->year%4==0)&&(p->year%100!=0)))&&(p->month>2))
		days+=1;
	printf("%d.%d is the %dth in %d\n",p->month,p->date,days,p->year);
	return 0;
}
