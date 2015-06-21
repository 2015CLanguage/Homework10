#include<stdio.h>
#include<stdlib.h>
#define N 10
struct Student
{
char num[10];
char name[10];
float score[3];
float avep;
}stu[N];

void save()
{
FILE*fp;
if((fp=fopen("stu.dat","wb"))==NULL)
	{
	printf("can not open the file!\n");
	exit(0);
	}
int i;
for(i=0;i<N;i++)
	{
	if(fwrite(&stu[i],sizeof(struct Student),1,fp)!=1)
		printf("file write error");
	}
fclose(fp);	
}

int main()
{
int i,j;
float sum;
for(i=0;i<N;i++)
	{
	printf("请输入第%d个学生的学号：",i+1);
	scanf("%s",&stu[i].num);
	printf("请输入该学生的姓名：");
	scanf("%s",&stu[i].name);
	printf("请输入该学生三门功课的成绩：");
	for(j=0;j<3;j++)
		{
		scanf("%f",&stu[i].score[j]);
		}
	}
for(i=0;i<N;i++)
	{
	sum=0
	for(j=0;j<3;j++)
		{sum=sum+stu[i].score[j];}
	stu[i].avep=sum/3.0;
	}
save();
return 0;
}
