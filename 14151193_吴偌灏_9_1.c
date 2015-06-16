#include <stdio.h>
#include <stdlib.h> 
struct date
{
	int day,month,year;
}d;
int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
void main()
{
	int flag=0,i,day=0;
	scanf("%d%d%d",&d.year,&d.month,&d.day);
	if(d.year%400==0||(d.year%400!=0&&d.year%4==0)) flag=1;
	if(d.month>12||d.month<1){printf("输入错误\n");exit(1);}
	if(d.day>month[d.month]||d.day<1){printf("输入错误\n");exit(1);}
	for (i=0; i<d.month; i++)  day=day+month[i];
	printf("是第%d天\n",day+d.day+flag);
}
