#include"stdio.h"
#define N 10
struct student
{
	char num[8];
	char name[10];
	float grade[3];
	float aver;
};
int main()
{
	struct student a[N];
	int i,j,mi;
	float sum,max,average;
	for(i=0;i<N;i++)
	{
		printf("输入第%d个同学\n",i+1);
		printf("学号:");
		scanf("%s",a[i].num); 
		printf("姓名:");
		scanf("%s",a[i].name); 
		for(j=0;j<3;j++)
		{
			printf("第%d课成绩:",j+1);
			scanf("%f",&a[i].grade[j]);
		}
	}
	printf("********************************************************************************\n");
	max=average=mi=0;
	for(i=0;i<N;i++)
	{
		sum=0;
		for(j=0;j<3;j++)
		{
			sum=sum+a[i].grade[j];
		}
		a[i].aver=sum/3.0;
		average=average+a[i].aver;
		if(sum>max)
		{
			max=sum;
			mi=i;
		}
	}
	average=average/N;
	printf("学号\t姓名\t科目1\t科目2\t科目3\t平均分\t\n"); 
	for(i=0;i<N;i++)
	{
		printf("%s\t%s\t",a[i].num,a[i].name);
		for(j=0;j<3;j++)
		{
			printf("%3.2f\t",a[i].grade[j]);
		}
		printf("%3.2f\n",a[i].aver);
	}
	printf("\n");
	printf("所有人平均分：%3.1f\n\n",average);
	printf("第%d位同学成绩最高：\n\n",mi+1);
	printf("学号:%s  姓名:%s  科目1:%3.2f  科目2:%3.2f  科目3:%3.2f  平均分:%3.2f",a[mi].num,a[mi].name,a[mi].grade[0],a[mi].grade[1],a[mi].grade[2],a[mi].aver);
}
