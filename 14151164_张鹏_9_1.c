#include"stdio.h"

struct Date
{
	int year;
	int month;
	int day;
};

int main()
{
	struct Date a1;
	int i,d=0;
	printf("输入年月日\n");
	scanf("%d%d%d",&a1.year,&a1.month,&a1.day);
	printf("%d年%d月%d日\n",a1.year,a1.month,a1.day);
	int m[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	if(  ((0 == a1.year%4)&&(0 != a1.year%100)) ||(0 == a1.year %400) )
		{
			m[1]=29;
			printf("是闰年\n");
		}
	for(i=0;i<a1.month-1;i++)
	{
		d=d+m[i];
	}
	d=d+a1.day;
	printf("是本年的第%d天",d);
	

}
