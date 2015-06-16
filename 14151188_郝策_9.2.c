#include"stdio.h"

struct Date
{
	int year;
	int month;
	int day;
};
int days(int ye, int mo, int da);

int main()
{
	struct Date a1;
	printf("输入年月日\n");
	scanf("%d%d%d",&a1.year,&a1.month,&a1.day);
	printf("%d年%d月%d日\n",a1.year,a1.month,a1.day);
	printf("是本年的第%d天",days(a1.year,a1.month,a1.day));
	

}

int days(int ye, int mo, int da)
{
	int i,d=0;
	int m[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	if(  ((0 == ye%4)&&(0 != ye%100)) ||(0 == ye%400) )
		{
			m[1]=29;
		}
	for(i=0;i<mo-1;i++)
	{
		d=d+m[i];
	}
	d=d+da;
	
	return d;
}
