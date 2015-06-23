#include<stdio.h>
struct student
{
	char num[6];
	char name[8];
	float score[3];
	float avr;
}stu[10];
void input(struct student stu[])
{	
	int i,j;
	for(i=0;i<10;i++)
	{
		printf("请输入第%d个学生的成绩:\n",i+1);
		printf("学号：");
		scanf("%s",stu[i].num);
		printf("姓名：");
		scanf("%s",stu[i].name);
		for (j=0;j<3;j++)
		{
			printf("第%d门课成绩：",j+1);
			scanf("%f",&stu[i].score[j]);
		}
	}
}
float cal(struct student stu[])
{
	int i,j,k=0;
	float sum,max=0,average=0;
	for(i=0;i<10;i++)
	{
		sum=0;
		for(j=0;j<3;j++)
			sum=sum+stu[i].score[j];
		stu[i].avr=sum/3.0;
		average=average+stu[i].avr;
		if(sum>max)
		{
			max=sum;
			k=i;
		}
	}
	printf("第%s学生有最高分，姓名为%s\n",stu[k].num,stu[k].name);
	printf("其分数为：%.2f,%.2f,%.2f,平均分为:%.2f\n",stu[k].score[0],stu[k].score[1],stu[k].score[2],stu[k].avr);
	average=average/10;
	return(average);
}
void main()
{
	int i,j,k;
	input(stu);
	printf("总平均分为：%3.2f\n",cal(stu));
}
