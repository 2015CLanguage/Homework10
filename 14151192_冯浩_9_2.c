#include <stdio.h>
int days();
struct 
{
	int day,month,year;
}D;
int m[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
	int r;
	printf("请输入年月日：\n");
	scanf("%d,%d,%d",&D.year,&D.month,&D.day);
	r=days();
	printf("该日为该年的第%d天。\n",r);
	return 0;
}
int days()
{
	int flag=0,i;
	printf("请输入年月日：\n");
	scanf("%d,%d,%d",&D.year,&D.month,&D.day);
	if (D.year%4==0&&D.year%100!=0||D.year%400==0) 
		flag=1;
	if (D.month==1)
		return D.day;
	if (D.month==2)
		return 31+D.day;
	if (D.month>=3)
	{
		int day=0;
		for (i=1; i<D.month; i++)  
			day=day+m[i];
		return day+D.day+flag;
	}
}
