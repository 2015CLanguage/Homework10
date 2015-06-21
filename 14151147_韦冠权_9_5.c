#include<stdio.h> 
#define N 10
struct
{
	char num[8];
	char name[20];
	float score[3];
	float aver;
}stu[N];
void main()
{
	int i, j, maxi;
	float sum, max;
	for (i = 0; i < N; i++)
	{
		printf("输入第 %d 个学生的信息:\n", i + 1);
		printf("学号:");
		scanf("%s", stu[i].num);
		printf("姓名:");
		scanf("%s",stu[i].name);
		for (j = 0; j < 3; j++)
		{
			printf("科目 %d 分数:", j + 1);
			scanf("%f", &stu[i].score[j]);
			
		}
	}
	max = 0;
	maxi = 0;
	for (i = 0; i < N; i++)
	{
		sum = 0;
		for (j = 0; j < 3; j++)
			sum = sum + stu[i].score[j];
		stu[i].aver = sum / 3.0;
		if (sum > max)
		{
			max = sum;
			maxi = i;
		}
	}
	printf("学号 \t姓名 \t科目一\t科目二\t科目三\t平均分\n");
	for (i = 0; i < N; i++)
	{
		printf("%s\t", stu[i].num);
		printf("%s\t", stu[i].name);
		for (j = 0; j < 3; j++)
		{
			printf("%6.2f\t", stu[i].score[j]);
		}
		printf("%6.2f", stu[i].aver);
		printf("\n");
	}
	printf("平均分最高的学生是:%s_%s\n", stu[maxi].num, stu[maxi].name);
	printf("他的各科成绩为:%5.2f,%5.2f,%5.2f,总平均分为:%5.2f", stu[maxi].score[0], stu[maxi].score[1], stu[maxi].score[2], stu[maxi].aver);
}
