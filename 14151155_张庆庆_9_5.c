#include<stdio.h>
# define N 2
struct student
{
             int num;
             char name[20];
             float score[3];
             float aver;
};
int main()
{

             void input(struct student stu[]);
             struct student max(struct student stu[]);
             void print(struct student stu);
             struct student stu[N],*p=stu;
             input(p);
             print(max(p));

             return 0;
}
void input(struct student stu[])
{
             int i,average=0,sum_aver=0;
             printf("请输入各学生的信息：学号，姓名，三门课成绩：\n");
             for(i=0;i<N;i++)
             {
                          scanf("%d%s%f%f%f",&stu[i].num,stu[i].name,&stu[i].score[0],&stu[i].score[1],&stu[i].score[2]);
                          stu[i].aver=(stu[i].score[0]+stu[i].score[1]+stu[i].score[2])/3.0;
                          average+=stu[i].aver;
             }
             average=sum_aver/N;
             printf("总的平均分是：%5.2f\n",average);
}
struct student max(struct student stu[])
{
             int i,m=0;
             for(i=0;i<N;i++)
                if(stu[i].aver>stu[m].aver) m=i;
             return stu[m];
}
void print(struct student stu)
{
             printf("成绩最高的学生是：\n");
             printf("学号：%d\n姓名：%s\n三门课成绩：%5.2f,%5.2f,%5.2f\n平均分成绩：%5.2f\n",stu.num,stu.name,stu.score[0],stu.score[1],stu.score[2],stu.aver);
}
