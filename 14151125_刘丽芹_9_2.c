#include "stdio.h"

struct time
{
    int year;
    int month;
    int day;
}date;

int days(int a,int b,int c);

void main()
{
    printf("请输入年，月，日：");
    scanf("%d,%d,%d",&date.year,&date.month,&date.day);
    days(date.year,date.month,date.day);
}

int days(int a,int b,int c)
{
    int i,days=0;
    int day_tab[12]={31,28,31,30,31,30,31,31,30,31,30,31};

    for(i=0;i<b-1;i++)
    {
        days=days+day_tab[i];
    }
    days=days+c;
    if((a%4==0 && a%100!=0 || a%400==0) && a>=3)
    {
        days=days+1;
    }
    printf("%d月%d日是%d年的第%d天。\n",b,c,a,days);
    return 0;
}
