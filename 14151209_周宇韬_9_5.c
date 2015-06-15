#include <stdio.h>

#define N 10

struct student{
    int num;
    char name[10];
    int score1;
    int score2;
    int score3;
}stu[N];

int main()
{
    int i;
    printf("录入学生信息:\n");
    for (i=0; i<N; i++)
    {
        printf("学号:");
        scanf("%d",&stu[i].num);
        printf("姓名:");
        scanf("%s",stu[i].name);
        printf("三门课的成绩:");
        scanf("%d,%d,%d",&stu[i].score1,&stu[i].score2,&stu[i].score3);
    }
    int Sum=0;
    float ave;
    float avei[N];
    for (i=0; i<N; i++)
    {
        Sum+=(stu[i].score1+stu[i].score2+stu[i].score3);
        avei[i]=(stu[i].score1+stu[i].score2+stu[i].score3)/3;
    }
    ave=Sum/(3*N);
    float max=avei[0];
    int maxi=0;
    for (i=0; i<N; i++)
    {
        if (avei[i]>max)
        {
            max=avei[i];
            maxi=i;
        }
    }
    printf("总平均:%.2f\n",ave);
    printf("成绩最好学生:学号%d,姓名%s,成绩1:%d,成绩2:%d,成绩3:%d,平均:%.2f\n",stu[maxi].num,stu[maxi].name,stu[maxi].score1,stu[maxi].score2,stu[maxi].score3,max);
    return 0;
}
