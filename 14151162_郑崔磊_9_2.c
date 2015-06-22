#include<stdio.h>
struct y_m_d
    {
        int year;
        int month;
        int day;
    } ;
int main()
{
    struct y_m_d date;
    int days(struct y_m_d date);
    printf("input the date:");
    scanf("%d%d%d",&date.year,&date.month,&date.day);
    printf("%d %d %d is the %dth day of the year",date.year,date.month,date.day,days(date));
    return 0;
}
int days(struct y_m_d date)
{
    int a[12],p=0,i;
    if((date.year%400)==0)
        {a[0]=31;a[1]=29;a[2]=31;a[3]=30;a[4]=31;a[5]=30;a[6]=31;a[7]=31;a[8]=30;a[9]=31;a[10]=30;a[11]=31;}
    if((date.year%4)==0&&(date.year%100)!=0)
        {a[0]=31;a[1]=29;a[2]=31;a[3]=30;a[4]=31;a[5]=30;a[6]=31;a[7]=31;a[8]=30;a[9]=31;a[10]=30;a[11]=31;}
    else
        {a[0]=31;a[1]=28;a[2]=31;a[3]=30;a[4]=31;a[5]=30;a[6]=31;a[7]=31;a[8]=30;a[9]=31;a[10]=30;a[11]=31;}
    for(i=0;i<date.month-1;i++)
        p=p+a[i];
    p=p+date.day;
    return (p);
}
