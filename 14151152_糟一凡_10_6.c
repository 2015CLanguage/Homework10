#include<stdio.h>
#define N 5
struct Student
{
	int index;
	char name[20];
	float score[3];
	float aver;
};
struct Student stu[N];
void save();
int main()
{
	int i;
	printf("请输入5个学生的学号，姓名，三门课的成绩：\n"); 
	for(i=0;i<N;i++)
	{
		scanf("%d%s%f%f%f",&stu[i].index,&stu[i].name,&stu[i].score[0],&stu[i].score[1],&stu[i].score[2]);
		stu[i].aver=(stu[i].score[0]+stu[i].score[1]+stu[i].score[2])/3.0; 
	}
	save();
	return 0;
}
void save()
{
	FILE *fp;
	int i;
	if((fp=fopen("stud.dat","wb"))==NULL)
	{
		printf("文件无法打开！\n");
	}
	for(i=0;i<N;i++)
	{
		if(fwrite(&stu[i],sizeof(struct Student),1,fp)!=1)
		{
			printf("数据写入错误！"); 
		}
	}
	fclose(fp);
}
