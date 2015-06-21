#include <stdio.h>

struct
{
	int day,month,year;
}D;
int m[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
	int flag=0,i;
	printf("请输入年月日：\n");
	scanf("%d,%d,%d",&D.year,&D.month,&D.day);
	if (D.year%4==0&&D.year%100!=0||D.year%400==0) 
		flag=1;
	if (D.month==1)
		printf("该日是本年中的第%d天。\n",D.day);
	if (D.month==2)
		printf("该日是本年中的第%d天。\n",31+D.day);
	if (D.month>=3)
	{
		int day=0;
		for (i=1; i<D.month; i++)  
			day=day+m[i];
		printf("该日是本年中的第%d天。\n",day+D.day+flag);
	}
	return 0;
}
