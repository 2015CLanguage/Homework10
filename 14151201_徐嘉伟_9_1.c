#include <stdio.h>
struct a
{
	int year;
	int month;
	int day;
}date;
int main()
{
	int b(int year,int month,int day);
	int sum;
	printf("请输入年月日:");
	scanf("%d,%d,%d",&date.year,&date.month,&date.day);
	sum=b(date.year,date.month,date.day);
	printf("这一天是这一年的第%d天",sum);
return 0;}

int b(int year,int month,int day)
{
	int sum,i;
	int c[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	sum=0;
	for(i=1;i<month;i++)
	    sum=sum+c[i];
	sum=sum+day;
	if((year%4==0&&year%100!=0||year%4==0)&&month>2)
	    sum=sum+1;
	return(sum);
}
