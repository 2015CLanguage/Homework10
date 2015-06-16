//
//  main.c
//  10_6
//
//  Created by MAC on 15/6/15.
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
    int i,j;
    if((fp=fopen("stud.dat","r"))==NULL){
        printf("can not be opened !\n");
        exit(0);
    }
    printf("stud:\n");
    for(i=0;fread(&stu[i],sizeof(struct stu_infor),1,fp)!=0;i++){
        printf("\n%8d%10s",stu[i].No,stu[i].name);
        for(j=0;j<3;j++)
            printf("%5.2f",stu[i].grade[j]);
        printf("%5.2f",stu[i].ave);
    }
    for(i=0;i<10;i++){
        for(j=i+1;j<10;j++){
            if(stu[i].ave<stu[j].ave){
                temp=stu[i];
                stu[i]=stu[j];
                stu[j]=temp;
            }
        }
    }
     fclose(fp);
    printf("\nstu_sort:\n");
    fp=fopen("stu_sort.dat","w");
    for(i=0;i<5;i++){
        fwrite(&stu[i],sizeof(struct stu_infor),1,fp);
        printf("\n%8d%10s",stu[i].No,stu[i].name);
        for(j=0;j<3;j++)
            printf("%5.2f",stu[i].grade[j]);
        printf("%5.2f",stu[i].ave);
    }
     fclose(fp);
    return 0;
}
