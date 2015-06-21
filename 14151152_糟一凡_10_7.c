#include<stdio.h>
#define N 6
struct Student
{
	int index;
	char name[20];
	float score[3];
	float aver;
};
struct Student stu[6],temp;
void save();
void insert();
int main()
{
    insert();
	save(); 
	return 0;
}
void save()
{
	FILE *fp;
	int i;
	if((fp=fopen("stu_sort2.dat","wb"))==NULL)
	{
		printf("文件无法打开！\n");
	}
	for(i=0;i<N;i++)
	{
		if(fwrite(&stu[i],sizeof(struct Student),1,fp)!=1)
		{
			printf("数据写入错误！"); 
		}
		printf("学号：%d 姓名：%s 三门课成绩：%5.1f %5.1f %5.1f 平均分数：%5.1f\n",stu[i].index,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].aver);
	}
	fclose(fp);
}
void insert()
{
	printf("请输入要插入的学生信息：\n");
	scanf("%d%s%f%f%f",&stu[N-1].index,&stu[N-1].name,&stu[N-1].score[0],&stu[N-1].score[1],&stu[N-1].score[2]);
	stu[N-1].aver=(stu[N-1].score[0]+stu[N-1].score[1]+stu[N-1].score[2])/3.0; 
	int i,j;
	FILE *fp1;
	fp1=fopen("stu_sort.dat","rb");
	for(i=0;i<N-1;i++)
	{
	    fread(&stu[i],sizeof(struct Student),1,fp1);
    }
    fclose(fp1);
    for (i=0; i<N; i++)
    {
	    for (j=i+1; j<N; j++)
	    {
	        if (stu[i].aver<stu[j].aver)
	        {
	  	        temp=stu[i];
				stu[i]=stu[j];
				stu[j]=temp;
	  	    }
	    }
    }
}



