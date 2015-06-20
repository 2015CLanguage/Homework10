#include<stdio.h>
struct Student
{
	int index;
	char name[20];
    float score[3];
	float avr;
}stu[10];


void main()
{
	int i,j;
	for(i=0;i<10;i++)
	{
		printf("请输入第%d个学生数据\n",i+1);
		printf("学号:\n");
	    scanf("%d",&stu[i].index);
	    printf("姓名:\n");
	    scanf("%s",stu[i].name);
	    for(j=0;j<3;j++)
		{
			printf("score %d:\n",j+1);
		    scanf("%f",&stu[i].score[j]);
		}
	}//输入数据
	float sum;
	for(i=0;i<10;i++)
	{
		sum=0;
		for(j=0;j<3;j++)
		{sum=sum+stu[i].score[j];}
		stu[i].avr=sum/3.0;
	}//计算三科平均分
	int m;float max=stu[0].score[0];
	for(i=0;i<10;i++)
	{
		for(j=0;j<3;j++)
		{
			if(stu[i].score[j]>max)
			{max=stu[i].score[j];m=i;}
		}
	}//找出最高分
	printf("结果为:\n");
	printf("index name  score1 score2 score3 average\n");
	for(i=0;i<10;i++)
	{
		printf("%6d%6s ",stu[i].index,stu[i].name);
		for(j=0;j<3;j++)
		{printf("%6.2f",stu[i].score[j]);}
		printf("%6.2f\n",stu[i].avr);
	}
	printf("\n最高分结果如下:\n");
	printf("index:%d  name:%s\n",stu[m].index,stu[m].name);
	printf("成绩为:");
	for(j=0;j<3;j++)
	{printf("%6.2f",stu[m].score[j]);}
	printf("平均分为:%6.2f\n",stu[m].avr);//输出数据
}
