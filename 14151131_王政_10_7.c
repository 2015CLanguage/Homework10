#include<stdio.h>
void insert();
void change();
struct Student
{
	int number;
	char name[20];
	int score[3];
	float average;
};
struct Student stu[6],temp;
void insert()
{
	printf("请输入要插入的学生信息：\n");
	scanf("%d%s%d%d%d",&stu[5].number,&stu[5].name,&stu[5].score[0],&stu[5].score[1],&stu[5].score[2]);
	stu[5].average=(stu[5].score[0]+stu[5].score[1]+stu[5].score[2])/3.0; 
	int i,j;
	FILE *fp1;
	fp1=fopen("stu_sort.dat","rb");
	for(i=0;i<5;i++)
	{
	    fread(&stu[i],sizeof(struct Student),1,fp1);
    }
    fclose(fp1);
    for (i=0;i<6;i++)
    {
	    for (j=i+1;j<6;j++)
	    {
	        if (stu[i].average<stu[j].average)
	        {
	  	        temp=stu[i];
				stu[i]=stu[j];
				stu[j]=temp;
	  	    }
	    }
    }
}
void change()
{
	FILE *fp;
	int i;
	if((fp=fopen("stu_sort_new.dat","wb"))==NULL)
	{
		printf("Error！\n");
	}
	for(i=0;i<6;i++)
	{
		if(fwrite(&stu[i],sizeof(struct Student),1,fp)!=1)
		{
			printf("Error！"); 
		}
		printf("学号：%d 姓名：%s 三门课成绩：%5d %5d %5d 平均分数：%5.1f\n",stu[i].number,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].average);
	}
	fclose(fp);
}
int main()
{
    insert();
	change();
	return 0;
}
