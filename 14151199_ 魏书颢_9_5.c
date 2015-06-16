#include"stdio.h"
struct Student
{
	char index[10];
	char name[10];
	float score[3];
	float average;
}Stu[10];
void main()
{
	int i,j,maxi;
	float Sum,ave,ave1,max;
	ave=0;
	printf("请输入数据\n");
	for(i=0;i<10;i++)
	{
		printf("No.\n");
	    scanf("%s",&Stu[i].index);
		printf("Name:\n");
		scanf("%s",&Stu[i].name);
		for(j=0;j<3;j++)
		{
			printf("score%d\n",j+1);
			scanf("%f",&Stu[i].score[j]);
		}
	}
    for(i=0;i<10;i++)
		Sum=0.0;
		for(j=0;j<3;j++)
		{
			Sum=Sum+Stu[i].score[j];
			Stu[i].average=Sum/3;
		}
	for(i=0;i<10;i++)
		max=Stu[0].average;
	    if(Stu[i].average>max)
		{
			max=Stu[i].average;
		    maxi=i;
		}
	for(i=0;i<10;i++)
		ave=ave+Stu[i].average;
	ave1=ave/10;
	printf("总平均分为%d\n",ave1);
	printf("分数最高为%s同学\n",Stu[maxi].name);
	printf("分数为%d,%d,%d\n",Stu[maxi].score[1],Stu[maxi].score[2],Stu[maxi].score[2]);
	printf("平均分%d\n",Stu[maxi].average);

	
}
