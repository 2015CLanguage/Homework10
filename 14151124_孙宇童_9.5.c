#include<stdio.h>
# define N 10
struct student
{
	char num[6];
	char name[8];
	float score[3];
	float avr;
}stu[N];
int main()
{
	int i,j,maxi;
	float sum, max,average;//max为当前最好成绩，maxi为当前最好成绩对应的下标序号，sum为第i个学生对应的总成绩
	for(i=0;i<N;i++)
	{
		printf("请输入第%d个学生的信息：\n",i+1);
		printf("学号:\n");
		scanf("%s",stu[i].num);
		printf("姓名:\n");
		scanf("%s",stu[i].name);
		for(j=0;j<3;j++)
		{
			printf("成绩%d:",j+1);
			scanf("%f",&stu[i].score[j]);
		}

	}
average=0;
max=0;
maxi=0;
for(i=0;i<N;i++)
{
	sum=0;
	for(j=0;j<3;j++)
		sum+=stu[i].score[j];
	stu[i].avr=sum/3.0;
	average+=stu[i].avr;
	if(sum>max)
	{max=sum;
	maxi=i;}
}

average/=N;
printf("NO. name score1 scor2 score3 average\n");
for(i=0;i<N;i++)
{
	printf("%5s%10s",stu[i].num,stu[i].name);
		for(j=0;j<3;j++)
			printf("%9.2f",stu[i].score[j]);
		printf("%8.2\n",stu[i].avr);

}
printf("average=%5.2f\n",average);
printf("最高分为学生%s,%s\n",stu[maxi].num,stu[maxi].name );
printf("分数为：%6.2f,%6.2f,%6.2f,平均分为%5.2f\n",stu[maxi].score[0],stu[maxi].score[1],stu[maxi].score[2],stu[maxi].avr);
return 0;}
