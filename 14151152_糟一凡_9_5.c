#include<stdio.h>
#define N 10
struct Student
{
	int index;
	char name[20];
	float score[3];
	float aver;
};
int main()
{
	struct Student stu[N];
	int i,j,flag=0;
	float s=0,max=stu[0].score[0];
	printf("请输入10个学生的学号，姓名，三门课的成绩：\n"); 
	for(i=0;i<N;i++)
	{
		scanf("%d%s%f%f%f",&stu[i].index,&stu[i].name,&stu[i].score[0],&stu[i].score[1],&stu[i].score[2]);
		stu[i].aver=(stu[i].score[0]+stu[i].score[1]+stu[i].score[2])/3.0; 
		s=s+stu[i].aver;
		for(j=0;j<3;j++)
		{
			if(max<stu[i].score[j])
			{
				max=stu[i].score[j];
				flag=i;
			}
		}
	}
	printf("三门课程总平均成绩为：%5.1f\n",s/float(N));
	printf("最高分学生的信息为：\n");
	printf("学号：%d 姓名：%s 三门课成绩：%5.1f %5.1f %5.1f 平均分数：%5.1f",stu[flag].index,stu[flag].name,stu[flag].score[0],stu[flag].score[1],stu[flag].score[2],stu[flag].aver);
	return 0;
}
