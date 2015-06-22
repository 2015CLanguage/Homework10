#include<stdio.h>
struct student
{
	char name;
	int number;
	int score[3];
};
void main()
{
	struct student test[10];
	int i,j,every_sum=0,score_sum=0,max=0,sum[10];
	printf("请输入每名学生的姓名、学号、各科成绩\n");
	for(i=0;i<10;i++)
	{
		scanf("%s",&test[i].name);
		scanf("%d",&test[i].number);
		for(j=0;j<3;j++)
		scanf("%d",&test[i].score[j]);
	}
	for(i=0;i<10;i++)
	{
		for(j=0;j<3;j++)
			every_sum=every_sum+test[i].score[j];
		sum[i]=every_sum;
	}
	for(i=0;i<10;i++)
		score_sum=score_sum+sum[i];
	printf("平均分为%d\n",score_sum/10);
	for(i=0;i<10;i++)
	{
		if(sum[max]<sum[i])
			max=i;
	}
	printf("最高分学生为%s，学号为%d，成绩为%d\n",test[max].name,test[max].number,sum[max]);
}
