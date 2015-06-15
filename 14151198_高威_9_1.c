#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
struct Date
{
	int day,month,year;
}D;
int m[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
	int flag=0,i;
	scanf("%d%d%d",&D.day,&D.month,&D.year);
	if (D.year%400==0 || (D.year%400!=0&&D.year%4==0) ) flag=1;
	if (D.month==1)  printf("%d\n",D.day);
	if (D.month==2)  printf("%d\n",31+D.day);
	if (D.month>=3)
	{
		int day=0;
		for (i=1; i<D.month; i++)  day=day+m[i];
		printf("%d\n",day+D.day+flag);
	}
	return 0;
}
