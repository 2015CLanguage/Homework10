//
//  main.c
//  9_5
//
//  Created by MAC on 15/6/14.
//  Copyright (c) 2015年 MAC. All rights reserved.
//

#include <stdio.h>
struct stu_infor{
    char name;
    int NO;
    float grade1;
    float grade2;
    float grade3;
    float ave;
}stu[10];
int main(int argc, const char * argv[]) {
    int i,t;
    void aver(struct stu_infor stu[10]);
    float top(struct stu_infor stu[10]);
    float sum=0;
    printf("please input student information !\n");
    printf("name  NO  grade1  grade2  grade3\n");
    for(i=0;i<10;i++){
        scanf("%c%d%f%f%f",&stu[i].name,&stu[i].NO,&stu[i].grade1,&stu[i].grade2,&stu[i].grade3);
        getchar();
    }
    printf("\n");
    aver(stu);
    t=top(stu);
    for(i=0;i<10;i++){
        sum=sum+stu[i].ave;
    }
    sum=sum/10;
    printf("name   NO   grade1   grade2   grade3   average\n");
    for(i=0;i<10;i++){
        printf("%c%8d%9.2f%9.2f%9.2f%9.2f\n",stu[i].name,stu[i].NO,stu[i].grade1,stu[i].grade2,stu[i].grade3,stu[i].ave);
    }
    printf("total average grade:%5.2f\n",sum);
    printf("Following is the information of the student who has the highest grade !\n\n");
    printf("name:%c\nNO:%d\ngrade1:%.2f\ngrade2:%.2f\ngrade3:%.2f\naveragegrade:%.2f\n",stu[t].name,stu[t].NO,stu[t].grade1,stu[t].grade2,stu[t].grade3,stu[t].ave);
    return 0;
}
void aver(struct stu_infor stu[10]){
    int i;
    for(i=0;i<10;i++){
        stu[i].ave=(stu[i].grade1+stu[i].grade2+stu[i].grade3)/3;
    }
}
float top(struct stu_infor stu[10]){
    float top=stu[0].ave;
    int i,temp=0;
    for(i=0;i<10;i++){
        if(top<stu[i].ave){
            top=stu[i].ave;
            temp=i;
        }
    }
    return temp;
}
