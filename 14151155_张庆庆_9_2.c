#include<stdio.h>
struct y_m_d
{
             int year;
             int month;
             int day;
}date;
int main()
{
             int days(int year,int month,int day);
             int days(int,int,int);
             int day_sum;
             printf("请输入年,月,日：");
             scanf("%d,%d,%d",&date.year,&date.month,&date.day);
             day_sum=days(date.year,date.month,date.day);
             printf("%d/%d 是 %d 年中的第 %d 天。\n",date.month,date.day,date.year,days);
             return 0;
}
int days(int year,int month,int day)
{
             int i,day_sum;
             int day_tab[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
             day_sum=0;
             for(i=1;i<month;i++)
                day_sum=day_sum+day_tab[i];
             day_sum=day_sum+day;
             if((year%4==0&&year%100!=0||year%400==0)&&month>=3)
                day_sum=day_sum+1;
             return(day_sum);
}
