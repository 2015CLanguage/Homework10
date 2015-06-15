#include<stdio.h>
struct date
{
	int year;
	int month;
	int day;
};
int main()
{
	struct date a;
	int b,s,i;
	printf("请输入年,月,日:\n");
	scanf("%d %d %d",&a.year,&a.month,&a.day);
	if(a.year%4==0 && a.year%100!=0 || a.year%400==0)
	{
		b=29;
	}
	else
	{
		b=28;
	}
	s=0;
	for(i=1;i<a.month;i++)
	{
		if(i==1 || i==3 || i==5 || i==7 || i==8 || i==10 || i==12)
		{
			s=s+31;
		}
		else if(i==2)
		{
			s=s+b;
		}
		else
		{
			s=s+30;
		}
	}
	s=s+a.day;
	printf("该日在本年中是第%d天\n",s);
	return 0;
}
