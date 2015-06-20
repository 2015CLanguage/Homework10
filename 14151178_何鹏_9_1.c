#include "stdio.h"
struct date
{
	int year;
	int month;
	int day;
}d;
int cal(struct date *p);
int main()
{
	int num;
	struct date *p=&d;
	printf("请依次输入年月日：");
	scanf("%d%d%D",&d.year,&d.month,&d.day);
	num=cal(p);
	printf("%d",num);
	return 0;
}

int cal(struct date *p)
{
	int num=0;
	int i,k;
	if(p->year%4!=0||(p->year%100==0&&p->year%400!=0))
	    k=0;
	else
	    k=1;
	int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	for(i=0;i<(p->month);i++)
	    num=num+a[i];
	if(k==1&&(p->month)>2)
	    num++;
	return num;
}
