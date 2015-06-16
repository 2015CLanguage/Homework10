#include <stdio.h>
struct date
{
    int year;
    int month;
    int day;
};
int main()
{
    struct date d;
    int days;
    printf("请输入年月日：");
    scanf("%d %d %d",&d.year,&d.month,&d.day);
    if((d.year%4==0&&d.year%100!=0)||d.year%400==0)
    {
        switch(d.month)
        {
            case 1: days=d.day;break;
            case 2: days=31+d.day;break;
            case 3: days=60+d.day;break;
            case 4: days=91+d.day;break;
            case 5: days=121+d.day;break;
            case 6: days=152+d.day;break;
            case 7: days=182+d.day;break;
            case 8: days=213+d.day;break;
            case 9: days=244+d.day;break;
            case 10: days=274+d.day;break;
            case 11: days=305+d.day;break;
            case 12: days=335+d.day;break;
            default: printf("输入错误");break;
        }
    }
    else
    {
        switch(d.month)
        {
            case 1: days=d.day;break;
            case 2: days=31+d.day;break;
            case 3: days=59+d.day;break;
            case 4: days=90+d.day;break;
            case 5: days=120+d.day;break;
            case 6: days=151+d.day;break;
            case 7: days=181+d.day;break;
            case 8: days=212+d.day;break;
            case 9: days=243+d.day;break;
            case 10: days=273+d.day;break;
            case 11: days=304+d.day;break;
            case 12: days=334+d.day;break;
            default: printf("输入错误");break;
        }
    }

    printf("the day is number %d day",days);
    return 0;
}
