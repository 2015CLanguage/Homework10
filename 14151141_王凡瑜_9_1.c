#include<stdio.h>

int days(struct Date date);

struct Date
{
	int year;
	int month;
	int day;
};

void main()
{
	struct Date date;
	printf("Please input a date in the format of Year Month Day.\n");
	scanf("%d %d %d",&date.year,&date.month,&date.day);
	printf("It is No.%d day in year %d.\n",days(date),date.year);
}

int days(struct Date date)
{
	int daynum[12]={31,28,31,30,31,30,31,31,30,31,30,31},s=0,*p=daynum;
	if((date.year%4==0&&date.year%100!=0)||date.year%400==0)
		*(p+1)=29;
	for(p=daynum;p<daynum+date.month-1;p++)
		s+=*p;
	return s+date.day;
}
