//
//  main.c
//  9_1
//
//  Created by MAC on 15/6/14.
//  Copyright (c) 2015年 MAC. All rights reserved.
//

#include <stdio.h>
struct {
        int year;
        int month;
        int day;
}date;
int main(int argc, const char * argv[]) {
    int days=0,i;
    int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    printf("please input year、month、day in order!\n");
    scanf("%d%d%d",&date.year,&date.month,&date.day);
    if(date.day>month[date.month]){
        printf("error! please run again !\n");
        return 0;
    }
    for(i=0;i<date.month;i++){
        days=days+month[i];
    }
    days+=date.day;
    if(((date.year%4==0&&date.year%100!=0)||date.year%400==0)&&date.month>2)
        days=days+1;
    printf("the date you input is the%5dth day in that year!\n",days);
    return 0;
}
