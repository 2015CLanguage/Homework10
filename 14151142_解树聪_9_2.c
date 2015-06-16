#include <stdio.h>
int days(int year,int month,int day);
struct date
{
	int year;
	int month;
	int day;
};

int days(int year,int month,int day)
{
	int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31},days=0,i;
	for(i=1;i<month;i++)
		days=days+a[i];
	days=days+day;
	if(month>=3 && (year%400==0||year%4==0 && year%100!=0))
		days=days+1;
	
	return (days);
}
int main()
{
	int k;
	struct date b;
	printf("请输入年、月、日：");
	scanf("%d,%d,%d",&b.year,&b.month,&b.day);
	k=days(b.year,b.month,b.day);
	printf("该天是这一年的第%d天\n",k);
	return 0;
}
