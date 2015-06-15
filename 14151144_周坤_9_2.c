# Homework10
#include <stdio.h>
struct Date
{
    int year;
    int month;
    int day;
};
int days(struct date d);
int main()
{
    struct date a;
    printf("请输入年月日：");
    scanf("%d %d %d",&a.year,&a.month,&a.day);
    printf("the day is number %d day",days(a));
    return 0;
}
int days(struct date d)
{
    if((d.year%4==0&&d.year%100!=0)||d.year%400==0)
    {
        switch(d.month)
        {
            case 1: return d.day;break;
            case 2: return 31+d.day;break;
            case 3: return 60+d.day;break;
            case 4: return 91+d.day;break;
            case 5: return 121+d.day;break;
            case 6: return 152+d.day;break;
            case 7: return 182+d.day;break;
            case 8: return 213+d.day;break;
            case 9: return 244+d.day;break;
            case 10: return 274+d.day;break;
            case 11: return 305+d.day;break;
            case 12: return 335+d.day;break;
            default: printf("输入错误");break;
        }
    }
    else
    {
        switch(d.month)
        {
            case 1: return d.day;break;
            case 2: return 31+d.day;break;
            case 3: return 59+d.day;break;
            case 4: return 90+d.day;break;
            case 5: return 120+d.day;break;
            case 6: return 151+d.day;break;
            case 7: return 181+d.day;break;
            case 8: return 212+d.day;break;
            case 9: return 243+d.day;break;
            case 10: return 273+d.day;break;
            case 11: return 304+d.day;break;
            case 12: return 334+d.day;break;
            default: printf("输入错误");break;
        }
    }
    return 0;
}
