#include <stdio.h>
struct Day
{
    int year;
    int month;
    int date;
};
int days(int,int,int);
int main()
{
    struct Day x;
    printf("please input the date(y,m,d):");
    scanf("%d,%d,%d",&x.year,&x.month,&x.date);
    printf("the day is the %d day of the year.\n",days(x.year,x.month,x.date));
    return 0;
}

int days(int y,int m,int d)
{
    int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    if((((y%4==0)&&(y%100!=0))||(y%400==0))&&(m>2))
       d=d+1;
    int n=d,i;
    for(i=1;i<m;i++)
        n+=a[i];
    return n;

}
