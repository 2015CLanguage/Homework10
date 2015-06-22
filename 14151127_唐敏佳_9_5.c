#include "stdio.h"

struct Student
{
    char num[10];
    char name[20];
    float score[3];
    float ave;
}stu[10];

int main()
{
    int i,j,maxi;
    float sum,max,average;

    for(i=0;i<10;i++)
    {
        printf("输入第%d个学生的分数：\n",i+1);
        printf("学号：");
        scanf("%s",stu[i].num);
        printf("姓名：");
        scanf("%s",stu[i].name);
        for(j=0;j<3;j++)
        {
            printf("score1 %d:",j+1);
            scanf("%f",&stu[i].score[j]);
        }
    }

    average=0;
    max=0;
    maxi=0;
    for(i=0;i<10;i++)
    {
        sum=0;
        for(j=0;j<3;j++)
        {
            sum+=stu[i].score[j];
        }
        stu[i].ave=sum/3.0;
        average+=stu[i].ave;
        if(sum>max)
        {
            max=sum;
            maxi=i;
        }
    }
    average=average/10;

    printf("NO. name score1 score2 score3 average\n");
    for(i=0;i<10;i++)
    {
        printf("%5s%10s",stu[i].num,stu[i].name);
        for(j=0;j<3;j++)
        {
            printf("%9.2f",stu[i].score[j]);
            printf("%8.2f\n",stu[i].ave);
        }
    }
    printf("平均分=%5.2f\n",average);
    printf("最高分是：第%s个学生%s\n",stu[maxi].num,stu[maxi].name);
    printf("他的分数为：%6.2f,%6.2f,%6.2f,平均分为：%5.2f\n",
           stu[maxi].score[0],stu[maxi].score[1],stu[maxi].score[2],stu[maxi].ave);
           return 0;
}
