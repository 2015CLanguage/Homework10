#include "stdio.h"
struct date
{
	int year;
	int month;
	int day;
}d;
int days(int year,int month,int day);
int main()
{
	int num;
	printf("请依次输入年月日：");
	scanf("%d%d%D",&d.year,&d.month,&d.day);
	num=days(d.year,d.month,d.day);
	printf("%d",num);
	return 0;
}

int days(int year,int month,int day)
{
	int num=0;
	int i,k;
	if(year%4!=0||(year%100==0&&year%400!=0))
	    k=0;
	else
	    k=1;
	int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	for(i=0;i<month;i++)
	    num=num+a[i];
	if(k==1&&month>2)
	    num++;
	return num;
}
