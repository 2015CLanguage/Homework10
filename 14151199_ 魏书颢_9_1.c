#include"stdio.h"
struct date
{
	int year;
    int month;
    int day;
}cal;
int main()
{
	int days;
	scanf("%d,%d,%d",&cal.year,&cal.month,&cal.day);
	switch(cal.month)
	{
	case 1:days=cal.day; break;
	case 2:days=31+cal.day; break;
	case 3:days=59+cal.day; break;
	case 4:days=90+cal.day; break;
	case 5:days=120+cal.day; break;
	case 6:days=151+cal.day; break;
	case 7:days=181+cal.day; break;
	case 8:days=212+cal.day; break;
	case 9:days=243+cal.day; break;
	case 10:days=273+cal.day; break;
	case 11:days=304+cal.day; break;
	case 12:days=334+cal.day; break;
	}
	if((cal.year/100!=0&&cal.year/4==0||cal.year/400==0)&&cal.month>=3)
	{days=days+1;}
	printf("%d",days);
	return 0;
}
