#include "stdio.h"
struct Student                  //定义结构体
{
	char num[8];
	char name[10];
	float score[3];
	float ave;
}stu[10];
void input()                   //输入数据
{
	printf("请输入:\n");
	for (int i = 0; i < 10; i++)
	{
		printf("第%d位:\n", i + 1);
		printf("学号:\n");
		scanf("%s",stu[i].num);
		printf("姓名:\n");
		scanf("%s",stu[i].name);
		for (int j = 0; j < 3; j++)
		{
			printf("学科%d:\n", j + 1);
			scanf("%f",& stu[i].score[j]);
		}
	}
}
void main()
{
	input();
	int i, j, t=0;
	float average = 0, max = 0, sum;
	for (i = 0; i < 10; i++)                    //计算
	{
		for (j = 0; j < 3; j++)
		{
			sum = 0;
			sum += stu[i].score[j];
		}
		stu[i].ave = sum / 3.0;
		average += stu[i].ave;
		if (sum>max)
		{
			max = sum;
			t = i;
		}
	}
	average = average / 10;
	printf("NO. name course1 course2 course3 average\n");              //输出结果
	for (i = 0; i < 10; i++)
	{
		printf("%5s%10s", stu[i].num, stu[i].name);
		for (j = 0; j < 3; j++)
		{
			printf("%9.2f", stu[i].score[j]);
			printf("%8.2f\n", stu[i].ave);
		}
	}
	printf("总平均成绩为:%5.2f\n", average);
	printf("最高分的学生学号和姓名为:\n学号:%s\t姓名:%s\n",stu[t].num,stu[t].name);
	printf("他的成绩为:%6.2f.%6.2f.%6.2f,平均分为:%5.2f\n", stu[t].score[0], stu[t].score[1], stu[t].score[2], stu[t].ave);
}
