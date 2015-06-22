#include<stdio.h>
struct Date
{
	int year;
	int month;
	int day;
};
void main()
{
	int i,a[12]={31,28,31,30,31,30,31,31,30,31,30,31},sum=0;
	struct Date days;
	printf("请输入年月日\n");
	scanf("%d",&days.year);
	scanf("%d",&days.month);
	scanf("%d",&days.day);
	if(days.year%100==0)
	{
		if(days.year%400==0)
			a[1]=29;
	}
	else if(days.year%4==0)
		a[1]=29;
	for(i=0;i<days.month-1;i++)
		sum=sum+a[i];
	sum=sum+days.day;
	printf("该日是第%d天\n",sum);
}
