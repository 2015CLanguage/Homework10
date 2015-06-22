#include<stdio.h>
struct Student
{
	int number;
	char name[15];
	int score[3];
	float average;
}stu[5];
int main()
{
	int j,i;
	float sum;
	struct Student temp;
	FILE *fp;
	for(i=0;i<5;i++)
	{
		printf("请输入第%d名学生的数据;\n",i+1);
		printf("学号：");
		scanf("%d",&stu[i].number);
		printf("姓名为：");
		scanf("%s",stu[i].name);
		sum=0;
		for(j=0;j<3;j++)
		{
			printf("请输入第%d门课成绩",j+1);
			scanf("%d",&stu[i].score[j]);
			sum=sum+stu[i].score[j];
		}
		stu[i].average=sum/3.0;
	}
	fp=fopen("stud","w");
	for(i=0;i<5;i++)
	{
		if(fwrite(&stu[i],sizeof(struct Student),1,fp)!=1)
			printf("Error!\n");
	}
	fclose(fp);
	for(i=0;i<4;i++)
	{
		for(j=0;j<4-i;j++)
		{
			if(stu[j].average<stu[j+1].average)
			{
				temp=stu[j];
				stu[j]=stu[j+1];
				stu[j+1]=temp;
			}
		}
	}
	fp=fopen("stud_sort","w");
	for(i=0;i<5;i++)
	{
		if(fwrite(&stu[i],sizeof(struct Student),1,fp)!=1)
			printf("Error!\n");
	}
	fp=fopen("stud_sort","r");
	for(i=0;i<5;i++)
	{
		fread(&stu[i],sizeof(struct Student),1,fp);
		printf("\n%d,%s,%.2f",stu[i].number,stu[i].name,stu[i].average);
	}
	return 0;
}
