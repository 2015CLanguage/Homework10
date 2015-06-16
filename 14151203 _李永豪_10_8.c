//
//  main.c
//  10_8
//
//  Created by MAC on 15/6/16.
//  Copyright (c) 2015年 MAC. All rights reserved.
//
#include <stdio.h>
#include<stdlib.h>
struct stu_infor{
    int No;
    char name[10];
    float grade[3];
    float ave;
}stu[10],temp;
int main(int argc, const char * argv[]) {
    FILE *fp;
    int i,j,n=0;
    //input  and calculate information!
    printf("please input the information of the newstudent !");
    printf("\nname:");
    scanf("%s",temp.name);
    printf("\nNo:");
    scanf("%d",&temp.No);
    for(i=0;i<3;i++){
        printf("\ngrade%d:",i+1);
        scanf("%f",&temp.grade[i]);
    }
    temp.ave=(temp.grade[1]+temp.grade[2]+temp.grade[0])/3;
    //open file stu_sort
    if((fp=fopen("stu_sort.dat","r"))==NULL){
        printf("can not be opened !\n");
        exit(0);
    }
    printf("\nstu_sort:\n");
    for(i=0;fread(&stu[i],sizeof(struct stu_infor),1,fp)!=0;i++){
        printf("\n%8d%10s",stu[i].No,stu[i].name);
        for(j=0;j<3;j++)
            printf("%5.2f",stu[i].grade[j]);
        printf("%5.2f",stu[i].ave);
    }
    for(i=8;i>=0;i--){
        if(temp.ave<stu[i].ave){
            n=i;
            break;
        }
    }
    //write in file stu_sort
    printf("\nnewstu_sort:\n");
    fp=fopen("stu_sort.dat","w");
 

    for(i=8;i>=n;i--){
        fread(&stu[i],sizeof(struct stu_infor),1,fp);
    }
    for(i=8;i>=n;i--){
        stu[i+1]=stu[i];
    }
    stu[n]=temp;
    fwrite(&stu[i],sizeof(struct stu_infor),1,fp);
    for(i=0;i<10;i++){
        printf("\n%8d%10s",stu[i].No,stu[i].name);
        for(j=0;j<3;j++)
            printf("%5.2f",stu[i].grade[j]);
        printf("%5.2f",stu[i].ave);
    }

    return 0;
}
