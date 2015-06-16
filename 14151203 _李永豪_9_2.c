//
//  main.c
//  9_2
//
//  Created by MAC on 15/6/14.
//  Copyright (c) 2015年 MAC. All rights reserved.
//

#include <stdio.h>
struct calculate{
    int year;
    int month;
    int day;
}date;
int main(int argc, const char * argv[]) {
    int days(struct calculate date);
    printf("please input year,month,day in order !\n");
    scanf("%d%d%d",&date.year,&date.month,&date.day);
    printf("the date is the%4dth day in that year !",days(date));
    return 0;
}
int days(struct calculate date){
    int days=0;
    switch(date.month){
        case 1:days=date.day;break;
        case 2:days=date.day+31;break;
        case 3:days=date.day+59;break;
        case 4:days=date.day+90;break;
        case 5:days=date.day+120;break;
        case 6:days=date.day+151;break;
        case 7:days=date.day+181;break;
        case 8:days=date.day+212;break;
        case 9:days=date.day+243;break;
        case 10:days=date.day+273;break;
        case 11:days=date.day+304;break;
        case 12:days=date.day+334;break;
    }
    if(((date.year%4==0&&date.year%100!=0)||date.year%400==0)&&date.month>2)
        days=days+1;
    return days;
}
