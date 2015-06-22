#include <stdio.h>
struct student
{
    int num;
    char name[20];
    float score[3];
    float aver;
}stu[10];
float average(struct student stu[10])
{
    int i,sum=0;
    for(i=0;i<10;i++)
    {
        sum=sum+stu[i].aver;
    }
    return sum/10;
}
int main()
{
    int i;
    float a,max;
    struct student temp;
    printf("请输入10名学生的信息：学号 姓名 三门课成绩\n");
    for(i=0;i<10;i++)
    {
        scanf("%d %s %f %f %f",&stu[i].num,stu[i].name,&stu[i].score[0],&stu[i].score[1],&stu[i].score[2]);
        stu[i].aver=(stu[i].score[0]+stu[i].score[1]+stu[i].score[2])/3;
        printf("\n");
    }
    a=average(stu);
    max=stu[0].aver;
    for(i=1;i<10;i++)
    {
        if(stu[i].aver>stu[0].aver)
        {
            temp=stu[0];
            stu[0]=stu[i];
            stu[i]=temp;
        }
    }
    printf("总平均成绩是%5.2f,成绩最高的学的学号是%d，姓名是%s，三门课的成绩是%5.2f,%5.2f,%5.2f 三门课的平均分是%f",a,stu[0].num,stu[0].name,stu[0].score[0],stu[0].score[1],stu[0].score[2],stu[0].aver);
    return 0;
}
