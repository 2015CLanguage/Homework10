#include <stdio.h>
struct date
{
	int year;
	int month;
	int day;
};

int main()
{
	struct date b;
	int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31},days=0,i;
	printf("请输入年、月、日：");
	scanf("%d,%d,%d",&b.year,&b.month,&b.day);
	for(i=1;i<b.month;i++)
		days=days+a[i];
	days=days+b.day;
	if(b.month>=3 && (b.year%400==0||b.year%4==0 && b.year%100!=0))
		days=days+1;
	printf("该天是这一年的第%d天\n",days);
	return 0;
}
